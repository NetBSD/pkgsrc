#!/usr/pkg/bin/python2.7

import json
import base64
import subprocess
import tempfile
import os
import sys

def printf(format, *args):
    sys.stdout.write(format % args)

disks = list()
config = dict()

# shut down /dev/stderr
os.close(2)

cmd = "/sbin/sysctl -n hw.disknames"
for disk in subprocess.check_output(cmd.split(" ")).split(" "):
	cmd = "/sbin/disklabel " + disk
	p = subprocess.Popen(cmd.split(" "), stdout=subprocess.PIPE)
	disklabel = p.communicate()[0].split("\n")
	for line in disklabel:
		if line and line.find("ISO9660") != -1:
			letter = line.split(":")[0].replace(" ", "")
			disks.append("/dev/" + disk + letter)

for n, dev in enumerate(disks):
	mount_cmd = "/sbin/mount " + dev + " /mnt"
	umount_cmd = "/sbin/umount " + dev
	meta_data_file = "/mnt/openstack/latest/meta_data.json"
	try:
		subprocess.call(mount_cmd.split(" "))
	except:
		next

	try:
		config = json.load(open(meta_data_file))
	except:
		try:
			subprocess.call(umount_cmd.split(" "))
		except:
			next
		next

	try:
		subprocess.call(umount_cmd.split(" "))
	except:
		next

	# or hostname?
	if "name" in config:
		printf("hostname %s;\n", config["name"])
		printf("echo '%s' > /etc/myname;\n", config["name"])

	if "random_seed" in config:
		tmp = tempfile.mkstemp()
		os.write(tmp[0], base64.b64decode(config["random_seed"]))
		printf("rndctl -L %s;\n", tmp[1])
		os.close(tmp[0])

	if "public_keys" in config:
		printf("mkdir -p /root/.ssh\n");
		for n, k in enumerate(config['public_keys']):
			cmd = "echo '%s %s' >> /root/.ssh/authorized_keys;\n"
			printf(cmd, config['public_keys'][k], k)

	if "admin_pass" in config:
		key = config["admin_pass"] + "\n"
		PIPE = subprocess.PIPE
		p = subprocess.Popen("pwhash", stdin=PIPE, stdout=PIPE)
		hash = p.communicate(key)[0].replace("\n", "")
		
		ptmp = open("/etc/ptmp", "wx")
		pwd = open("/etc/master.passwd", "r")
		lines = pwd.readlines()
		pwd.close()
		for line in lines:
			if line.find("root:") == 0:
				fields = line.split(":")
				fields[1] = hash
				line = ":".join(fields)
			ptmp.write(line)
		ptmp.close()
		printf("pwd_mkdb -p /etc/ptmp;\n")
		


