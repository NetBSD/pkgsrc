# $NetBSD: Makefile,v 1.5 2001/10/09 19:40:54 jlam Exp $

DISTNAME=	mcrypt-2.5.10
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/old/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	replacement to crypt(1), supports many crypto algorithms

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../security/libmcrypt/buildlink.mk"
.include "../../security/mhash/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
