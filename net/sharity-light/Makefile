# $NetBSD: Makefile,v 1.12 2016/09/01 12:58:46 mef Exp $
#

DISTNAME=	Sharity-Light.1.3
PKGNAME=	sharity-light-1.3
CATEGORIES=	net
MASTER_SITES=	http://www.obdev.at/ftp/pub/Products/Sharity-Light/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.obdev.at/products/sharity-light/
COMMENT=	Userland smbfs -- SMB to NFS protocol converter
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-* # SMB is all native

# avoid picking up a bad value from a users environment
MAKE_ENV+=	"ARCH=	"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

post-extract:
	${MKDIR} ${WRKDIR}/unshlight
	${LN} -s ${FILESDIR}/unshlight.c ${WRKDIR}/unshlight
	${LN} -s ${FILESDIR}/Makefile.unshlight ${WRKDIR}/unshlight/Makefile

post-build:
	cd ${WRKDIR}/unshlight && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shlight ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unshlight/unshlight ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sharity-light
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ.txt \
		${DESTDIR}${PREFIX}/share/doc/sharity-light/
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/shlight.8

.include "../../mk/bsd.pkg.mk"
