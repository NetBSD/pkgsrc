# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_mysql-0.20150922
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/mysql/
COMMENT=	Erlang MySQL driver
LICENSE=	modified-bsd

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	mysql
GITHUB_TAG=	dfa87da95f8fdb92e270741c2a53f796b682f918
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_mysql

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_mysql/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
