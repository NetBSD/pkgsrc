# $NetBSD: Makefile,v 1.70 2026/07/28 14:57:09 ryoon Exp $

DISTNAME=	konoha-1.0.0-952
PKGNAME=	konoha-1.0.0.952
PKGREVISION=	64
CATEGORIES=	lang
#MASTER_SITES=	http://konoha.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
#HOMEPAGE=	http://konohascript.org/
COMMENT=	Statically-typed scripting langauge
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/konoha-1.0.0
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.10
CMAKE_CONFIGURE_ARGS+=	-DOpenGL_FOUND=False

post-extract:
	# Do not try to build these.
	## Cannot build with the recent freeglut.
	${RM} -rf ${WRKSRC}/package/konoha.opengl
	## Do not add java to dependencies.
	${RM} -rf ${WRKSRC}/package/konoha.compiler.java

.include "../../devel/cmake/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
