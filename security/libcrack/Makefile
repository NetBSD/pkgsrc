# $NetBSD: Makefile,v 1.18.16.1 2016/11/03 19:50:12 bsiegert Exp $
#

DISTNAME=	cracklib,2.7
PKGNAME=	libcrack-2.7
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.crypticide.com/alecm/security/cracklib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.crypticide.com/alecm/security/cracklib/cracklib,2.7.txt
COMMENT=	Password checking library

USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin include/cracklib lib libdata

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/cracklib
	${INSTALL_DATA} ${FILESDIR}/crack.h ${DESTDIR}${PREFIX}/include/cracklib
	cd ${WRKSRC}/cracklib &&					\
	${LIBTOOL} --mode=install ${INSTALL_DATA} libcrack.la ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} packer.h ${DESTDIR}${PREFIX}/include/cracklib
	${INSTALL_SCRIPT} ${WRKSRC}/util/mkdict ${DESTDIR}${PREFIX}/bin/libcrack_mkdict
.for util in packer testlib testnum teststr unpacker
	cd ${WRKSRC}/util &&						\
	${INSTALL_PROGRAM} ${util} ${DESTDIR}${PREFIX}/bin/libcrack_${util}
.endfor

.include "../../mk/bsd.pkg.mk"
