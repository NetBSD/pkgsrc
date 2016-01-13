# $NetBSD: Makefile,v 1.2 2016/01/13 15:24:48 fhajny Exp $

DISTNAME=	p1_utils-1.0.2
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_utils/
COMMENT=	Erlang Utility Modules from ProcessOne
LICENSE=	apache-2.0

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	p1_utils
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_utils

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_utils/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
