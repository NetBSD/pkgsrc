# $NetBSD: Makefile,v 1.8 2004/11/13 10:01:50 jmmv Exp $
#

DISTNAME=	gpgme-0.3.16
PKGNAME=	${DISTNAME:S/-/03-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy (0.3 branch)

DEPENDS+=	gnupg>=1.2.0:../../security/gnupg

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--without-gpgsm

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

.include "../../mk/bsd.pkg.mk"
