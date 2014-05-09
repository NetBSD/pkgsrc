# $NetBSD: Makefile,v 1.22 2014/05/09 07:37:17 wiz Exp $

DISTNAME=		Mixminion-0.0.8alpha3
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		6
CATEGORIES=		security mail
MASTER_SITES=		http://mixminion.net/dist/0.0.8alpha3/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://mixminion.net/
COMMENT=		Anonymous Type 3 remailer
LICENSE=		mit

REPLACE_PYTHON=	lib/mixminion/Main.py
PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 0.0.8alpha3

TEST_TARGET=		test

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
