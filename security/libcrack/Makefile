# $NetBSD: Makefile,v 1.9 2004/01/05 23:35:58 jlam Exp $
#

DISTNAME=	cracklib,2.7
PKGNAME=	libcrack-2.7
CATEGORIES=	security
MASTER_SITES=	http://www.users.dircon.co.uk/~crypto/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.users.dircon.co.uk/~crypto/
COMMENT=	Password checking library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin include/cracklib lib libdata

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/cracklib
	${INSTALL_DATA} ${FILESDIR}/crack.h ${PREFIX}/include/cracklib
	cd ${WRKSRC}/cracklib &&					\
	${LIBTOOL} --mode=install ${INSTALL_DATA} libcrack.la ${PREFIX}/lib && \
	${INSTALL_DATA} packer.h ${PREFIX}/include/cracklib
	${INSTALL_SCRIPT} ${WRKSRC}/util/mkdict ${PREFIX}/bin/libcrack_mkdict
.for util in packer testlib testnum teststr unpacker
	cd ${WRKSRC}/util &&						\
	${INSTALL_PROGRAM} ${util} ${PREFIX}/bin/libcrack_${util}
.endfor

.include "../../mk/bsd.pkg.mk"
