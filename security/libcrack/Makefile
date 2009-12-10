# $NetBSD: Makefile,v 1.16 2009/12/10 23:30:53 abs Exp $
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
PKG_DESTDIR_SUPPORT=user-destdir

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
