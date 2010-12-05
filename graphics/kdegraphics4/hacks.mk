# $NetBSD: hacks.mk,v 1.2 2010/12/05 23:22:10 wiz Exp $

#
# Can't figure out why the kruler build is prefering the below file
# rather than the one generated in _KDE_build/kruler so for the
# time being just get rid of it.
#

post-configure:
	rm ${BUILDLINK_DIR}/include/kruler.h
