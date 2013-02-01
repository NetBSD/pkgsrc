# $NetBSD: Makefile,v 1.25 2013/02/01 22:21:10 wiz Exp $

DISTNAME=	libksba-1.2.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
TEXINFO_REQD=		4.0

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
