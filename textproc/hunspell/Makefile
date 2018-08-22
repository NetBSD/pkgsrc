# $NetBSD: Makefile,v 1.26 2018/08/22 09:46:46 wiz Exp $

DISTNAME=	hunspell-1.3.3
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Improved spellchecker
LICENSE=	mpl-1.1 OR gnu-lgpl-v2.1 OR gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME:C/-[0-9]+$//}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl:run
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++03

CONFIGURE_ARGS+=	--with-ui

PKGCONFIG_OVERRIDE+=	hunspell.pc.in

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing default path to dictionaries.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	man/hunspell.1 man/hu/hunspell.1 src/tools/hunspell.cxx
SUBST_SED.paths+=	-e 's,/usr/share/hunspell,${PREFIX}/share/hunspell,g'
# Trailing slash important to not change hunspell.cxx
SUBST_SED.paths+=	-e 's,/usr/share/myspell/,${PREFIX}/share/hunspell/,g'

PLIST_SRC=		PLIST
PLIST_SUBST+=		DISTNAME=${DISTNAME}

REPLACE_PERL=	src/tools/ispellaff2myspell

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
