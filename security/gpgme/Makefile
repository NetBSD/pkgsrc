# $NetBSD: Makefile,v 1.91 2018/12/12 16:48:15 adam Exp $

DISTNAME=	gpgme-1.12.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/related_software/gpgme/
COMMENT=	GnuPG Made Easy
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
INFO_FILES=		yes

SUBST_CLASSES+=		pthread
SUBST_FILES.pthread=	src/gpgme-config.in
SUBST_SED.pthread+=	-e 's,@PTHREAD_LIBS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.pthread+=	-e 's,@PTHREAD_CFLAGS@,${PTHREAD_CFLAGS},g'
SUBST_STAGE.pthread=	pre-configure

CPPFLAGS.Darwin=	-D_POSIX_C_SOURCE=200809L
LIBS.SunOS+=		-lnsl -lsocket

TEST_TARGET=		check

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.0.2
.include "../../security/libassuan2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.28
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
