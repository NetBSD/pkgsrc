# $NetBSD: fonts.mk,v 1.19 2022/09/26 16:17:10 ryoon Exp $
#
# Install .otf and .ttf font files.
#
# The following variables may be used to tweak the installation path:
#
# TTF_FONTS_DIR is the install directory for .ttf files
#
# OTF_FONTS_DIR is the install directory for .otf files

USE_LANGUAGES?=	# none

TTF_FONTS_DIR?=		${PREFIX}/share/fonts/X11/TTF
OTF_FONTS_DIR?=		${PREFIX}/share/fonts/X11/OTF

INSTALLATION_DIRS+=	${TTF_FONTS_DIR} ${OTF_FONTS_DIR}

do-install: install-fonts

install-fonts:
	@${STEP_MSG} "Installing all .otf and .ttf files from ${WRKSRC}"
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -name '*.[tT][tT][fFcC]' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${TTF_FONTS_DIR} ";"
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -name '*.[oO][tT][fFcC]' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${OTF_FONTS_DIR} ";"

