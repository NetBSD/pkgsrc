# $NetBSD: Makefile,v 1.14 2003/12/14 15:05:01 wiz Exp $
#

DISTNAME=	gpgme-0.4.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

DEPENDS+=	gnupg>=1.2.2:../../security/gnupg

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

TEST_TARGET=		check

.include "../../mk/pthread.buildlink2.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFO_FILES=		gpgme.info

.include "../../security/libgpg-error/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
