# $NetBSD: Makefile,v 1.33 2019/11/04 21:12:55 rillig Exp $

DISTNAME=		Mixminion-0.0.8alpha3
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		8
CATEGORIES=		security mail
MASTER_SITES=		https://mixminion.net/dist/0.0.8alpha3/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		https://mixminion.net/
COMMENT=		Anonymous Type 3 remailer
LICENSE=		mit

REPLACE_PYTHON=	lib/mixminion/Main.py
PYTHON_VERSIONS_ACCEPTED= 27 # not yet ported as of 0.0.8alpha3

TEST_TARGET=		test

MAKE_ENV+=		OPENSSL_PREFIX=${BUILDLINK_PREFIX.openssl:Q}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
