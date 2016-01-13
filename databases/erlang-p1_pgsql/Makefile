# $NetBSD: Makefile,v 1.2 2016/01/13 15:06:34 fhajny Exp $

DISTNAME=	p1_pgsql-1.0.0
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/pgsql/
COMMENT=	Pure Erlang PostgreSQL driver
LICENSE=	erlang-public-license

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	pgsql
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_pgsql

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_pgsql/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
