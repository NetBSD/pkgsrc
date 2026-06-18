# $NetBSD: Makefile,v 1.24 2026/06/18 14:27:56 nia Exp $
#

DISTNAME=	cracklib,2.7
PKGNAME=	libcrack-2.7
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	-https://alecmuffett.com/alecm/software/cracklib/cracklib%2C2.7.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alecmuffett.com/alecm/software/cracklib/cracklib%2C2.7.txt
COMMENT=	Password checking library

USE_LIBTOOL=	YES

# This uses K&R style function definitions and is unlikely to
# be happy with an evolving C standard. gnu99 is chosen for
# being the minimum bootstrap requirement and safety against
# APIs being hidden in strict standards mode.
FORCE_C_STD=	gnu99

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
