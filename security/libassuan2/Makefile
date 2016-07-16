# $NetBSD: Makefile,v 1.11 2016/07/16 08:20:56 wiz Exp $

DISTNAME=	libassuan-2.4.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=	.tar.bz2
CONFLICTS=	libassuan-1.*{,nb*}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnupg.org/related_software/libassuan/index.en.html
COMMENT=	IPC library used by some of the other GnuPG related packages
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
