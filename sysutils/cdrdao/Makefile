# $NetBSD: Makefile,v 1.7 2001/05/19 12:47:05 drochner Exp $
#

DISTNAME=		${PKGNAME}.src
PKGNAME=		cdrdao-1.1.5
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		sysutils
MASTER_SITES=		http://prdownloads.sourceforge.net/cdrdao/

MAINTAINER=		David Maxwell <david@maxwell.net>
HOMEPAGE=		http://cdrdao.sourceforge.net/
COMMENT=		Records audio or data CD-Rs in disk-at-once (DAO) mode

BUILD_DEPENDS+=		pccts-1.33.22:../../devel/pccts

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS+=	--with-pcctsbin=${PREFIX}/bin
CONFIGURE_ARGS+=	--with-pcctsinc=${PREFIX}/include/pccts
CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-gtkmm-exec-prefix=/dev/null
# don't pick up an installed libcdda_paranoia
LDFLAGS+=		-L../paranoia

#override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""

post-configure:
	cd ${WRKSRC}/scsilib/RULES ; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${MACHINE}-netbsd-cc.rul;

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
