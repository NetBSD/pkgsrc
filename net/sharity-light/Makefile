# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:28 jlam Exp $
#

DISTNAME=	Sharity-Light.1.2
PKGNAME=	sharity-light-1.2
CATEGORIES=	net
MASTER_SITES=	http://www.obdev.at/ftp/pub/Products/Sharity-Light/ \
		ftp://ftp.obdev.at/pub/Products/Sharity-Light/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.obdev.at/Products/shlight.html
COMMENT=	Userland smbfs -- SMB to NFS protocol converter

# avoid picking up a bad value from a users environment
MAKE_ENV+=	"ARCH=	"

INSTALLATION_DIRS=	man/man8 sbin

post-extract:
	${MKDIR} ${WRKDIR}/unshlight
	${LN} -s ${FILESDIR}/unshlight.c ${WRKDIR}/unshlight
	${LN} -s ${FILESDIR}/Makefile.unshlight ${WRKDIR}/unshlight/Makefile

post-build:
	cd ${WRKDIR}/unshlight && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shlight ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unshlight/unshlight ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sharity-light
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ.txt \
		${PREFIX}/share/doc/sharity-light/
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8/shlight.8

.include "../../mk/bsd.pkg.mk"
