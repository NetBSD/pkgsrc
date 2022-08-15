# $NetBSD: Makefile,v 1.1 2022/08/15 14:44:24 wiz Exp $

DISTNAME=	preftools-v0.9
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	http://www.public-software-group.org/pub/projects/preftools/v0.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.public-software-group.org/preftools
COMMENT=	Command line utilities for ballot counting
LICENSE=	mit

USE_LANGUAGES=	# none

LUA_VERSIONS_ACCEPTED=	51

REPLACE_LUA+=	propor
REPLACE_LUA+=	schulze
REPLACE_LUA+=	schulze-simple

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/preftools
INSTALLATION_DIRS+=	share/doc/preftools/example-data-propor
INSTALLATION_DIRS+=	share/doc/preftools/example-data-schulze

do-build:

do-install:
.for f in ${REPLACE_LUA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DESTDIR}${PREFIX}/share/doc/preftools
	${INSTALL_DATA} ${WRKSRC}/doc/example-data-propor/* ${DESTDIR}${PREFIX}/share/doc/preftools/example-data-propor/
	${INSTALL_DATA} ${WRKSRC}/doc/example-data-schulze/* ${DESTDIR}${PREFIX}/share/doc/preftools/example-data-schulze/

.include "../../lang/lua/application.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
