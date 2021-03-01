# $NetBSD: Makefile,v 1.34 2021/03/01 09:48:40 nia Exp $

DISTNAME=	ivtools-2.0.4a1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=vectaport/}
GITHUB_PROJECT=	ivtools
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ivtools.sourceforge.net/ivtools/index.html
COMMENT=	Drawing editors for PostScript, TeX, and web graphics
LICENSE=	modified-bsd # close enough

CONFLICTS+=	dclock-[0-9]*

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	gmake bash:run
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

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
