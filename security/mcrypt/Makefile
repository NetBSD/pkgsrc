# $NetBSD: Makefile,v 1.6 2002/08/25 21:50:39 jlam Exp $

DISTNAME=	mcrypt-2.5.10
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/old/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	replacement to crypt(1), supports many crypto algorithms

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../security/libmcrypt/buildlink2.mk"
.include "../../security/mhash/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
