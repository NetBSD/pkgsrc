# $NetBSD: Makefile,v 1.67 2005/11/08 17:58:18 tv Exp $
#

DISTNAME=		pth-2.0.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library

CONFLICTS=		pth-current-[0-9]* pth-syscall<1.4.1nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--with-fdsetsize=1024
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
