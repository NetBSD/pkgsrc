# $NetBSD: Makefile,v 1.41 2026/01/04 10:19:38 wiz Exp $

DISTNAME=	ivtools-2.0.4a1
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=vectaport/}
GITHUB_PROJECT=	ivtools
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ivtools.sourceforge.net/ivtools/index.html
COMMENT=	Drawing editors for PostScript, TeX, and web graphics
LICENSE=	modified-bsd # close enough

# ps2pdf
TOOL_DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS+=	dclock-[0-9]*

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	gmake bash:run
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-D_POSIX_C_SOURCE=200112L

REPLACE_BASH+=	src/scripts/comterp_run.bash
REPLACE_BASH+=	src/scripts/ivgetjpg.bash
REPLACE_BASH+=	src/scripts/ivtiftopnm.bash

REPLACE_INTERPRETER+=	comterp
REPLACE.comterp.old=	/usr/bin/env comterp_run
REPLACE.comterp.new=	${PREFIX}/bin/comterp_run
REPLACE_FILES.comterp=	src/scripts/csvfilt

SUBST_CLASSES+=		gsf
SUBST_STAGE.gsf=	pre-configure
SUBST_MESSAGE.gsf=	Correcting the path to Ghostscript fonts.
SUBST_FILES.gsf+=	configure.ac
SUBST_SED.gsf+=		-e "s,/usr/share/ghostscript/fonts,${PREFIX}/share/ghostscript/fonts,g"

CONFIGURE_ARGS=		--with-tiff=${BUILDLINK_PREFIX.tiff}
CONFIGURE_ARGS+=	--without-ace
CONFIGURE_ARGS+=	--without-clippoly

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
