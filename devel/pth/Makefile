# $NetBSD: Makefile,v 1.31 2000/10/06 09:03:17 jlam Exp $
#

DISTNAME=		pth-1.3.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html

CONFLICTS=		pth-current-*
# for PLIST
VERS=			13.27

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-pthread
PLIST_SUBST+=		VERS=${VERS}

test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
