# $NetBSD: Makefile,v 1.7 2002/11/24 13:51:33 chris Exp $

DISTNAME=	gpgme-0.3.13
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

DEPENDS+=	gnupg>=1.2.0:../../security/gnupg

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFOFILES=		gpgme.info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
