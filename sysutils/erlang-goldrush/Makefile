# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	goldrush-0.1.7
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=DeadZen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/DeadZen/goldrush/
COMMENT=	Small, Fast event processing and monitoring for Erlang/OTP apps
LICENSE=	mit

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	goldrush
GITHUB_TAG=	${PKGVERSION_NOREV}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/goldrush

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/goldrush/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
