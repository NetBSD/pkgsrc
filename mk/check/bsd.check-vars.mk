# $NetBSD: bsd.check-vars.mk,v 1.3 2006/06/09 16:12:08 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_FILES_SUPPORTED?=		yes
CHECK_SHLIBS_SUPPORTED?=	yes

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
