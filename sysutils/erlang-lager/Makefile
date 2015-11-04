# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	lager-3.0.1
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=basho/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/basho/lager/
COMMENT=	Logging framework for Erlang/OTP
LICENSE=	apache-2.0

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-goldrush-[0-9]*:../../sysutils/erlang-goldrush

GITHUB_PROJECT=	lager
GITHUB_TAG=	${PKGVERSION_NOREV}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/lager

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/lager/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
