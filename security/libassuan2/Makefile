# $NetBSD: Makefile,v 1.1.1.1 2010/07/03 04:45:38 manu Exp $
#

DISTNAME=	libassuan-2.0.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=	.tar.bz2
CONFLICTS=	libassuan-1.*{,nb*}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/libassuan/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--infodir=${PREFIX}/info
INFO_FILES=	yes

.include "../../security/libgpg-error/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
