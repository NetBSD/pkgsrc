# $NetBSD: Makefile,v 1.1.1.1 2000/02/18 15:13:50 wiz Exp $
#

DISTNAME=	cdrdao-1.1.3.src
PKGNAME=	cdrdao-1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ping.de/sites/daneb/

MAINTAINER=	David Maxwell <david@maxwell.net>
HOMEPAGE=	http://www.ping.de/sites/daneb/cdrdao.html

BUILD_DEPENDS=  antlr:../../devel/pccts \
		dlg:../../devel/pccts \
		genmk:../../devel/pccts \
		sor:../../devel/pccts

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+=	--with-pcctsbin=${PREFIX}/bin
CONFIGURE_ARGS+=	--with-pcctsinc=${PREFIX}/include/pccts
CONFIGURE_ARGS+=	--without-posix-threads

WRKSRC=		${WRKDIR}/cdrdao-1.1.3

post-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cdrdao
		${INSTALL_MAN} ${WRKSRC}/COPYING \
			${WRKSRC}/README \
			${WRKSRC}/Release-1.1.2 \
			${WRKSRC}/Release-1.1.3 \
			${WRKSRC}/CREDITS \
			${WRKSRC}/README.FreeBSD \
			${WRKSRC}/INSTALL \
			${WRKSRC}/README.PlexDAE \
			${PREFIX}/share/doc/cdrdao
		${INSTALL_MAN} ${WRKSRC}/edc_ecc/README \
			${PREFIX}/share/doc/cdrdao/README.edc_ecc
		${INSTALL_MAN} ${WRKSRC}/edc_ecc/crc.txt \
			${PREFIX}/share/doc/cdrdao/crc.txt
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cdrdao/testtocs
		${INSTALL_MAN} ${WRKSRC}/testtocs/*.toc \
			${PREFIX}/share/doc/cdrdao/testtocs
		${INSTALL_MAN_DIR} ${PREFIX}/share/examples/cdrdao
		${INSTALL_MAN} ${WRKSRC}/contrib/mp32dao/mp32dao.pl \
			${PREFIX}/share/examples/cdrdao
		${INSTALL_MAN} ${WRKSRC}/contrib/mp32dao/README \
			${PREFIX}/share/examples/cdrdao/README.mp32dao
		${INSTALL_MAN_DIR} ${PREFIX}/share/examples/cdrdao/psxcopy
		${INSTALL_MAN} ${WRKSRC}/contrib/psxcopy-0.2/Makefile \
			${WRKSRC}/contrib/psxcopy-0.2/README \
			${WRKSRC}/contrib/psxcopy-0.2/cdjob.c \
			${WRKSRC}/contrib/psxcopy-0.2/cdjob.c \
			${WRKSRC}/contrib/psxcopy-0.2/psxdump.c \
			${WRKSRC}/contrib/psxcopy-0.2/read-psx \
			${WRKSRC}/contrib/psxcopy-0.2/write-psx \
			${PREFIX}/share/examples/cdrdao/psxcopy
		${INSTALL_MAN} ${WRKSRC}/contrib/wav2dao/wav2dao.pl \
			${PREFIX}/share/examples/cdrdao

.include "../../mk/bsd.pkg.mk"
