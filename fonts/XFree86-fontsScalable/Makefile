# $NetBSD: Makefile,v 1.4 2004/03/28 22:06:15 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsScalable-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-4.4.0-src-4.tgz XFree86-4.4.0-src-5.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 scalable fonts

DEPENDS+=	XFree86-fontsEncodings>=4.4.0:../XFree86-fontsEncodings

NO_BUILD=		yes
NO_BUILDLINK=		# defined
USE_LANGUAGES=		# empty
NO_XFREE86_TARGETS=	# defined

FONT_TYPES=		Speedo TTF Type1

do-install:
.for fnt in ${FONT_TYPES}
	${INSTALL_DATA_DIR} ${X11ROOT}/lib/X11/fonts/${fnt}
.endfor
.undef fnt
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
.undef f
# because fonts.mk does not do this yet
.for fnt in ${FONT_TYPES}
	${X11ROOT}/bin/mkfontscale ${X11ROOT}/lib/X11/fonts/${fnt}
	${X11ROOT}/bin/mkfontdir ${X11ROOT}/lib/X11/fonts/${fnt}
.endfor
.undef fnt
	${X11ROOT}/bin/mkfontdir -e ${X11ROOT}/lib/X11/fonts/encodings \
		-e ${X11ROOT}/lib/X11/fonts/encodings/large \
		${X11ROOT}/lib/X11/fonts/Speedo \
		${X11ROOT}/lib/X11/fonts/TTF \
		${X11ROOT}/lib/X11/fonts/Type1
	${LOCALBASE}/bin/fc-cache ${X11ROOT}/lib/X11/fonts/TTF
	${LOCALBASE}/bin/fc-cache ${X11ROOT}/lib/X11/fonts/Type1

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
