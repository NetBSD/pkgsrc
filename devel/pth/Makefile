# $NetBSD: Makefile,v 1.80 2017/08/29 11:40:13 wiz Exp $

DISTNAME=		pth-2.0.7
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library
LICENSE=		gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--enable-debug

TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-syscall-hard
.elif ${OPSYS} == "Interix" || ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_check_nfdstype='unsigned int'
CONFIGURE_ENV+=		ac_cv_typedef_nfds_t=no # in <poll.h>, but that's unused
.endif

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
