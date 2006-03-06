# $NetBSD: texinfo.mk,v 1.33 2006/03/06 05:25:45 jlam Exp $

#
# This Makefile fragment is included by bsd.pkg.mk when INFO_FILES is
# not empty.
#

.if !defined(TEXINFO_MK)
TEXINFO_MK=	# defined

.if !empty(INFO_FILES)
#
# Handle install-info.
# 

# Pathname relative to ${PREFIX} of directory holding the info
# files and the Info dir file.
INFO_DIR?=	info

USE_TOOLS+=	install-info:run

# Generate INSTALL/DEINSTALL scripts code for handling install-info.
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/install-info
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/install-info
FILES_SUBST+=		INFO_FILES=${INFO_FILES:Q}
FILES_SUBST+=		INSTALL_INFO=${INSTALL_INFO:Q}
FILES_SUBST+=		INFO_DIR=${INFO_DIR:Q}
.endif # INFO_FILES

.endif # TEXINFO_MK
