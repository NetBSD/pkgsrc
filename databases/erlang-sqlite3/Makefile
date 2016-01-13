# $NetBSD: Makefile,v 1.2 2016/01/13 15:08:15 fhajny Exp $

DISTNAME=	sqlite3-1.1.5.20151221
PKGNAME=	erlang-${DISTNAME:S/_/-/g}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexeyr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/alexeyr/erlang-sqlite3/
COMMENT=	Sqlite gen_server port for Erlang
LICENSE=	erlang-public-license

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	erlang-sqlite3
GITHUB_TAG=	cbc3505f7a131254265d3ef56191b2581b8cc172
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pax

MAKE_FILE=		GNUmakefile
INSTALLATION_DIRS+=	lib/erlang/lib/sqlite3

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/sqlite3/

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
