# $NetBSD: Makefile,v 1.76 2012/10/31 11:19:26 asau Exp $
#

DISTNAME=		pth-2.0.7
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		pth-current-[0-9]* pth-syscall<1.4.1nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
#CONFIGURE_ARGS+=	--enable-debug

TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "m68k" && (!empty(OS_VERSION:M1.5.[12]*) || !empty(OS_VERSION:M1.[0-4]*))
pre-configure:
	@${ECHO} Building without --enable-syscall-hard. lib/18644 needs fixing.
.  else
CONFIGURE_ARGS+=	--enable-syscall-hard
.  endif
.elif ${OPSYS} == "Interix"
CONFIGURE_ENV+=		ac_cv_check_nfdstype='unsigned int'
CONFIGURE_ENV+=		ac_cv_typedef_nfds_t=no # in <poll.h>, but that's unused
.endif

# XXX: Check this is still required and reverse test to OS which need it.
.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--with-fdsetsize=1024
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
