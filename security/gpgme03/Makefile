# $NetBSD: Makefile,v 1.13 2009/02/17 13:02:20 joerg Exp $
#

DISTNAME=	gpgme-0.3.16
PKGNAME=	${DISTNAME:S/-/03-/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/related_software/gpgme/
COMMENT=	GnuPG Made Easy (0.3 branch)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gnupg>=1.2.0:../../security/gnupg

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--without-gpgsm

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

.include "../../mk/bsd.pkg.mk"
