# $NetBSD: Makefile,v 1.29 2000/07/03 11:08:12 rh Exp $
#

DISTNAME=		pth-1.3.6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html

CONFLICTS=		pth-current-*
# for PLIST
VERS=			13.26

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-pthread
PLIST_SUBST+=		VERS=${VERS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCE AUTHORS COPYING HACKING \
		NEWS README SUPPORT TESTS THANKS USERS pthread.ps rse-pmt.ps \
			${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
