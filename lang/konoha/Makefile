# $NetBSD: Makefile,v 1.5 2012/12/16 01:52:17 obache Exp $
#

DISTNAME=	konoha-1.0.0-952
PKGNAME=	konoha-1.0.0.952
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://konoha.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://konohascript.org/
COMMENT=	Statically-typed scripting langauge
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/konoha-1.0.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
