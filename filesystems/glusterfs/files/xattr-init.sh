#!/bin/sh

# $NetBSD: xattr-init.sh,v 1.8 2011/08/09 07:15:42 manu Exp $

GLUSTERFS_XATTR="
  trusted.distribute.linkinfo
  trusted.distribute.fix.layout
  trusted.glusterfs.pathinfo
  trusted.glusterfs.volume-mark
  trusted.glusterfs.test
  trusted.posix1.gen
  trusted.gfid
  trusted.afr
  glusterfs.open-fd-count
  glusterfs.inodelk-count
  glusterfs.entrylk-count
  glusterfs.posixlk-count
"

test $# -ne 1 && {
	echo "usage: $0 /export/volume/path"
	exit 1
}

VOLUME=$1

test -d ${VOLUME} || {
	echo "$0: ${VOLUME} is not a directory"
	exit 1
}

mkdir -p ${VOLUME}/.attribute/user || {
	echo "$0: cannot create ${VOLUME}/.attribute/user"
	exit 1
}

mkdir -p ${VOLUME}/.attribute/system || {
	echo "$0: cannot create ${VOLUME}/.attribute/system"
	exit 1
}

extattrctl start ${VOLUME} || {
	echo "$0: cannot start extended attributes on ${VOLUME}"
	exit 1
}

for attr in ${GLUSTERFS_XATTR} ; do
	ns="user";
	echo ${attr} | egrep -q '^(trusted|system|security)\.' && ns="system"

	attrfile=${VOLUME}/.attribute/${ns}/${attr}

	test -e ${attrfile} && {
		echo "$0: ${attrfile} exists."
		exit 1
	}

	extattrctl initattr 1024 ${attrfile} || {
		echo "$0: cannot initialize ${attrfile}"
		exit 1
	}

	extattrctl enable ${VOLUME} ${ns} ${attr} ${attrfile} || {
		echo "$0: cannot enable ${attr} backed by ${attrfile}"
		exit 1
	}
done
