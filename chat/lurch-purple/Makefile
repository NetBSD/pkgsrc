# $NetBSD: Makefile,v 1.9 2020/06/02 08:23:19 adam Exp $

VERSION=	0.6.8
DISTNAME=	lurch-${VERSION}-src
PKGNAME=	lurch-purple-${VERSION}
PKGREVISION=	5
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_GITHUB:=gkdr/lurch/releases/download/v${VERSION}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gkdr/lurch
COMMENT=	XEP-0384: OMEMO Encryption for libpurple
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/lurch-${VERSION}
USE_TOOLS+=	cmake gmake pkg-config
USE_LANGUAGES=	c c++

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/mxml/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
