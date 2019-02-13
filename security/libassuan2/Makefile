# $NetBSD: Makefile,v 1.19 2019/02/13 16:05:48 adam Exp $

DISTNAME=	libassuan-2.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libassuan/
MASTER_SITES+=	http://mirrors.dotsrc.org/gcrypt/libassuan/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnupg.org/related_software/libassuan/index.en.html
COMMENT=	IPC library used by some of the other GnuPG related packages
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	src/libassuan.pc.in
TEST_TARGET=		check

CONFLICTS=	libassuan-1.*

BUILDLINK_ABI_DEPENDS.libgpg-error+=	libgpg-error>=1.17
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
