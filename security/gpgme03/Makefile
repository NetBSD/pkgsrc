# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 17:51:04 wiz Exp $
#

DISTNAME=	gpgme-0.3.15
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

DEPENDS+=	gnupg>=1.2.0:../../security/gnupg

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink2.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFO_FILES=		gpgme.info

.include "../../mk/bsd.pkg.mk"
