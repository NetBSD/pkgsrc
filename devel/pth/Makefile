# $NetBSD: Makefile,v 1.48 2002/08/29 19:44:07 skrll Exp $
#

DISTNAME=		pth-1.4.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library

CONFLICTS=		pth-current-[0-9]* pth-syscall<1.4.1nb1

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-syscall-hard
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

# for PLIST
PTH_MAJOR=		14
PTH_MINOR=		21
PLIST_SUBST+=		PTH_MAJOR=${PTH_MAJOR} PTH_MINOR=${PTH_MINOR}

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test | \
		tee ${WRKSRC}/test.log

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
