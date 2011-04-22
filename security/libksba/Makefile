# $NetBSD: Makefile,v 1.23 2011/04/22 13:42:47 obache Exp $

DISTNAME=	libksba-1.2.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
TEXINFO_REQD=		4.0

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
