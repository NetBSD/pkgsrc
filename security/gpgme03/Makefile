# $NetBSD: Makefile,v 1.4 2004/02/14 18:45:25 minskim Exp $
#

DISTNAME=	gpgme-0.3.15
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

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

INFO_FILES=		gpgme.info

.include "../../mk/bsd.pkg.mk"
