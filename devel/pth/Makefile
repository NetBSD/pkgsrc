# $NetBSD: Makefile,v 1.36 2001/09/27 23:17:57 jlam Exp $
#

DISTNAME=		pth-1.4.0
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
