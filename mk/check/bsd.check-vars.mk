# $NetBSD: bsd.check-vars.mk,v 1.4 2007/08/20 11:04:02 joerg Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_FILES_SUPPORTED?=		yes
CHECK_SHLIBS_SUPPORTED?=	yes
USE_CHECK_SHLIBS_ELF?=		no

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true

.if !empty(USE_CHECK_SHLIBS_ELF:M[yY][eE][sS])
USE_TOOLS+=	readelf
.endif
