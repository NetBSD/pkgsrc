# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_stun-0.20150916
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stun/
COMMENT=	STUN for ejabberd
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_tls-[0-9]*:../../security/erlang-p1_tls
DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	stun
GITHUB_TAG=	061bdae484268cbf0457ad4797e74b8516df3ad1
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

BUILD_TARGET=	src

INSTALLATION_DIRS+=	lib/erlang/lib/p1_stun

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_stun/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
