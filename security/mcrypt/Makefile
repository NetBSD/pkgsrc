# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:10 tv Exp $

DISTNAME=	mcrypt-2.6.4
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/old/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	Replacement to crypt(1), supports many crypto algorithms

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
