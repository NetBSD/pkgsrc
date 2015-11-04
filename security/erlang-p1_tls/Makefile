# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	p1_tls-0.20150803
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/tls/
COMMENT=	TLS/SSL native driver for Erlang
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	tls
GITHUB_TAG=	e56321afd974e9da33da913cd31beebc8e73e75f
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_tls

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_tls/

.include "../../lang/erlang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
