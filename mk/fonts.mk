# $NetBSD: fonts.mk,v 1.18 2021/11/13 22:21:20 nia Exp $
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
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -name '*.[tT][tT][fF]' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${TTF_FONTS_DIR} ";"
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -name '*.[oO][tT][fF]' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${OTF_FONTS_DIR} ";"

