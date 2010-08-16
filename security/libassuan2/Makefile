# $NetBSD: Makefile,v 1.2 2010/08/16 21:42:18 wiz Exp $
#

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

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--infodir=${PREFIX}/info
INFO_FILES=	yes

.include "../../security/libgpg-error/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
