# $NetBSD: Makefile,v 1.3 2011/04/12 13:17:20 adam Exp $

DISTNAME=	libassuan-2.0.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=	.tar.bz2
CONFLICTS=	libassuan-1.*{,nb*}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/libassuan/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
INFO_FILES=		yes

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
