# $NetBSD: Makefile,v 1.14 2010/01/17 12:02:41 wiz Exp $
#

DISTNAME=		Mixminion-0.0.8alpha3
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		1
CATEGORIES=		security mail
MASTER_SITES=		http://mixminion.net/dist/0.0.8alpha3/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://mixminion.net/
COMMENT=		Anonymous Type 3 remailer
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

TEST_TARGET=		test

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
