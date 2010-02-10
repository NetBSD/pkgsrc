# $NetBSD: Makefile,v 1.15 2010/02/10 19:17:45 joerg Exp $
#

DISTNAME=		Mixminion-0.0.8alpha3
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		2
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
