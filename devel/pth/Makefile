# $NetBSD: Makefile,v 1.82 2025/04/21 16:07:29 wiz Exp $

DISTNAME=		pth-2.0.7
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library
LICENSE=		gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS.NetBSD+=	--enable-syscall-hard
CONFIGURE_ENV.Darwin+=	ac_cv_check_nfdstype='unsigned int'
CONFIGURE_ENV.Darwin+=	ac_cv_typedef_nfds_t=no

PLIST_VARS+=		pthread

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--enable-pthread
PLIST.pthread=		yes
.endif

INSTALLATION_DIRS=	share/doc/pth

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${DESTDIR}${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
