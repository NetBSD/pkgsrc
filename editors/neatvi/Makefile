# $NetBSD: Makefile,v 1.1 2019/07/07 14:59:43 leot Exp $

DISTNAME=	neatvi-06
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aligrudi/neatvi/
COMMENT=	Small vi/ex editor for editing bidirectional UTF-8 text
LICENSE=	isc

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Honors user's CC, CFLAGS and LDFLAGS
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's/cc/${CC}/'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'

INSTALLATION_DIRS+=	bin share/doc/neatvi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vi ${DESTDIR}${PREFIX}/bin/neatvi
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/neatvi

.include "../../mk/bsd.pkg.mk"
