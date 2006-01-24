# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:07 wiz Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsScalable-${XF_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-${XF_VER}-src-4.tgz XFree86-${XF_VER}-src-5.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 scalable fonts

DEPENDS+=	XFree86-fontsEncodings>=${XF_VER}:../../fonts/XFree86-fontsEncodings

NO_BUILD=		yes
USE_LANGUAGES=		# empty
NO_XFREE86_TARGETS=	yes

FONT_TYPES=		Speedo TTF Type1

do-install:
.for fnt in ${FONT_TYPES}
	${INSTALL_DATA_DIR} ${X11ROOT}/lib/X11/fonts/${fnt}
.endfor
	${INSTALL_DATA} ${WRKDIR}/xc/fonts/scaled/Speedo/font0*.spd \
		${X11ROOT}/lib/X11/fonts/Speedo
	${INSTALL_DATA} ${WRKDIR}/xc/fonts/scaled/Speedo/COPYRIGHT \
		${X11ROOT}/lib/X11/fonts/Speedo/
	${INSTALL_DATA} ${WRKDIR}/xc/fonts/scaled/TTF/luxi*.ttf \
		${X11ROOT}/lib/X11/fonts/TTF/
	${INSTALL_DATA} ${WRKDIR}/xc/fonts/scaled/TTF/COPYRIGHT.BH \
		${X11ROOT}/lib/X11/fonts/TTF/Luxi-COPYRIGHT.BH
.for f in afm pfa pfb
	${INSTALL_DATA} ${WRKDIR}/xc/fonts/scaled/Type1/*.${f} \
		${X11ROOT}/lib/X11/fonts/Type1
.endfor
# because fonts.mk does not do this yet
.for fnt in ${FONT_TYPES}
	${X11ROOT}/bin/mkfontscale ${X11ROOT}/lib/X11/fonts/${fnt}
	${X11ROOT}/bin/mkfontdir ${X11ROOT}/lib/X11/fonts/${fnt}
.endfor
	${X11ROOT}/bin/mkfontdir -e ${X11ROOT}/lib/X11/fonts/encodings \
		-e ${X11ROOT}/lib/X11/fonts/encodings/large \
		${X11ROOT}/lib/X11/fonts/Speedo \
		${X11ROOT}/lib/X11/fonts/TTF \
		${X11ROOT}/lib/X11/fonts/Type1
	${LOCALBASE}/bin/fc-cache ${X11ROOT}/lib/X11/fonts/TTF
	${LOCALBASE}/bin/fc-cache ${X11ROOT}/lib/X11/fonts/Type1

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
