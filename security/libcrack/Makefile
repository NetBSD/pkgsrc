# $NetBSD: Makefile,v 1.15 2009/10/28 18:50:53 drochner Exp $
#

DISTNAME=	cracklib,2.7
PKGNAME=	libcrack-2.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.crypticide.com/alecm/security/cracklib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.crypticide.com/alecm/security/cracklib/cracklib,2.7.txt
COMMENT=	Password checking library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
