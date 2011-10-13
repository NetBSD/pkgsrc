#!/bin/sh
#
# mkmemstick.sh: Create memory stick image from NetBSD installation CDs
#
# Copyright (C) 2009 Jared D. McNeill <jmcneill@NetBSD.org>

src="$1"
img="$2"
dstbase="/tmp/makeimg$(id -u)"
dst="${dstbase}/rootfs"
tmpimg="${dstbase}/netbsd.img"
disklabel="
type: unknown
disk: Memory Stick
label: 
flags:
bytes/sector: 512
sectors/track: 63
tracks/cylinder: 16
sectors/cylinder: 1000
cylinders: @TCYLINDERS@
total sectors: @TSECTORS@
rpm: 3600
interleave: 1
trackskew: 0
cylinderskew: 0
headswitch: 0
track-to-track seek: 0
drivedata: 0 

16 partitions:
 a: @SECTORS@ 0 4.2BSD 1024 8192 0
 d: @SECTORS@ 0 unused 0 0
"
vnddev="vnd0"
vndmnt="${dstbase}/mnt"

die() {
	echo "fatal: $0"
	exit 2
}

if [ -z "$img" ]; then
	echo "usage: $0 source.iso memdisk.img"
	exit 1
fi

if [ ! -r "$src" ]; then
	echo "$src not found"
	exit 1
fi

if [ -d "$dst" ]; then
	echo "$dst already exists"
	exit 1
fi
if [ -f "$img" ]; then
	echo "$img already exists"
	exit 1
fi

mkdir -p "$dst" || die "couldn't create directory $dst"

printf " => extracting iso image..."
vnconfig "$vnddev" "$src"
mkdir "$vndmnt"
mount -r -t cd9660 "/dev/${vnddev}a" "$vndmnt"
(cd "$vndmnt" && tar cf - .) | (cd "$dst" && tar xf -)
printf " done.\n"

if [ -f "${dst}/boot.cfg" ]; then
	echo " => patching bootloader banner"
	cp "${dst}/boot.cfg" "${dstbase}/boot.cfg" || die "couldn't copy boot.cfg to ${dstbase}"
	cat "${dstbase}/boot.cfg" | sed 's/installation CD/installation memory stick/' > "${dst}/boot.cfg"
fi
echo " => copying /usr/mdec/boot to $dst"
cp /usr/mdec/boot "$dst" || die "couldn't copy /usr/mdec/boot"

echo " => building filesystem image"
makefs "$img" "$dst" || die "couldn't build filesystem image"

echo " => installing bootxx_ffsv1"
/usr/sbin/installboot "$img" /usr/mdec/bootxx_ffsv1 || die "couldn't install bootxx_ffsv1"

echo " => writing disklabel"
imgsize=$(stat -L -f %z "${img}")
echo "$disklabel" | \
	sed "s/@SECTORS@/$(expr $imgsize / 512)/" | \
	sed "s/@TCYLINDERS@/$(expr $imgsize / 512 / 1000 + 1)/" | \
	sed "s/@TSECTORS@/$(expr $imgsize / 512 + 1)/" >${dstbase}/disklabel
disklabel -R -F "${img}" "${dstbase}/disklabel" || die "couldn't write disklabel"

echo " => cleaning up"
umount "${vndmnt}"
vnconfig -u "${vnddev}"
rm -rf "${dstbase}"

echo " => done!"
