# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_utils-0.20151016
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_utils/
COMMENT=	Erlang Utility Modules from ProcessOne
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	p1_utils
GITHUB_TAG=	d7800881e6702723ce58b7646b60c9e4cd25d563
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_utils

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_utils/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
