# $NetBSD: Makefile,v 1.3 2001/02/17 17:49:48 wiz Exp $
#

DISTNAME=	cracklib,2.7
PKGNAME=	libcrack-2.7
CATEGORIES=	security
MASTER_SITES=	http://www.users.dircon.co.uk/~crypto/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.users.dircon.co.uk/~crypto/
COMMENT=	password checking library

USE_LIBTOOL=	YES

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
