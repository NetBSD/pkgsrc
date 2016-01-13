# $NetBSD: Makefile,v 1.2 2016/01/13 15:05:23 fhajny Exp $

DISTNAME=	p1_mysql-1.0.0
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/mysql/
COMMENT=	Erlang MySQL driver
LICENSE=	modified-bsd

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	mysql
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_mysql

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_mysql/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
