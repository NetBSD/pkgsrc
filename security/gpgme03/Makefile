# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:52 jlam Exp $
#

DISTNAME=	gpgme-0.3.15
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy (0.3 branch)

DEPENDS+=	gnupg>=1.2.0:../../security/gnupg

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink2.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

INFO_FILES=		gpgme.info

.include "../../mk/bsd.pkg.mk"
