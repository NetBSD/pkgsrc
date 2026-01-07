# $NetBSD: Makefile,v 1.67 2026/01/07 08:47:38 wiz Exp $

DISTNAME=	konoha-1.0.0-952
PKGNAME=	konoha-1.0.0.952
PKGREVISION=	61
CATEGORIES=	lang
#MASTER_SITES=	http://konoha.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
#HOMEPAGE=	http://konohascript.org/
COMMENT=	Statically-typed scripting langauge
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/konoha-1.0.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
