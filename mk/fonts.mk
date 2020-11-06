# $NetBSD: fonts.mk,v 1.17 2020/11/06 18:04:27 maya Exp $
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
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -iname '*.ttf' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${TTF_FONTS_DIR} ";"
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -iname '*.otf' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${OTF_FONTS_DIR} ";"

