# $NetBSD: Makefile,v 1.28 2017/09/03 08:53:14 wiz Exp $

DISTNAME=		Mixminion-0.0.8alpha3
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		7
CATEGORIES=		security mail
MASTER_SITES=		https://mixminion.net/dist/0.0.8alpha3/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		https://mixminion.net/
COMMENT=		Anonymous Type 3 remailer
LICENSE=		mit

REPLACE_PYTHON=	lib/mixminion/Main.py
PYTHON_VERSIONS_INCOMPATIBLE=  34 35 36 # not yet ported as of 0.0.8alpha3

TEST_TARGET=		test

MAKE_ENV+=		OPENSSL_PREFIX=${BUILDLINK_PREFIX.openssl:Q}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
