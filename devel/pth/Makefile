# $NetBSD: Makefile,v 1.38 2002/02/12 14:59:59 mrauch Exp $
#

DISTNAME=		pth-1.4.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library

CONFLICTS=		pth-current-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-pthread
.if (${MACHINE_ARCH} == "i386" && ${CFLAGS:M-O2} == "-O2")
CFLAGS:=		${CFLAGS:S/-O2/-O0/}
.endif

# for PLIST
PTH_MAJOR=		14
PTH_MINOR=		20
PLIST_SUBST+=		PTH_MAJOR=${PTH_MAJOR} PTH_MINOR=${PTH_MINOR}

test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
