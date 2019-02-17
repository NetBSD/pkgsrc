# $NetBSD: Makefile,v 1.4 2019/02/17 21:19:53 leot Exp $

DISTNAME=	sfeed-0.9.8
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/sfeed/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/sfeed/file/README.html
COMMENT=	RSS and Atom parser
LICENSE=	isc

USE_LANGUAGES=	c99

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'

REPLACE_SH+=		sfeed_opml_export sfeed_update

.include "../../mk/bsd.pkg.mk"
