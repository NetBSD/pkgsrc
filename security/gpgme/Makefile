# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:09 tv Exp $
#

DISTNAME=	gpgme-0.9.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

DEPENDS+=	gnupg>=1.2.2:../../security/gnupg

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

LIBS.SunOS+=		-lnsl -lsocket

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

INFO_FILES=		gpgme.info

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
