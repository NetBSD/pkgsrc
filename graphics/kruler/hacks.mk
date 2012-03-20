# $NetBSD: hacks.mk,v 1.1 2012/03/20 00:14:35 markd Exp $

#
# Can't figure out why the kruler build is prefering the below file
# rather than the one generated in _KDE_build/kruler so for the
# time being just get rid of it.
#

post-configure:
	rm ${BUILDLINK_DIR}/include/kruler.h
