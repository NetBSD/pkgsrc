#!@PYTHON@

import sys

from setuptools.command.easy_install import PthDistributions
from pkg_resources import find_distributions

usage = "@PYPREFIX@-manage-eggs [ register | unregister ] egg\n"

if len(sys.argv) != 3 or sys.argv[1] not in ("register", "unregister"):
	sys.stderr.write(usage)
	sys.exit(1)

pth = PthDistributions("@PYSITELIB@/easy-install.pth")
distrib = find_distributions(sys.argv[2], True).next()
if sys.argv[1] == "register":
	pth.add(distrib)
elif sys.argv[1] == "unregister":
	pth.remove(distrib)
pth.save()
