# $NetBSD: Makefile,v 1.17 2004/06/20 19:05:25 dillo Exp $
#

DISTNAME=		cdrdao-1.1.9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdrdao/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://cdrdao.sourceforge.net/
COMMENT=		Records audio or data CD-Rs in disk-at-once (DAO) mode

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-pcctsbin=${PREFIX}/bin
CONFIGURE_ARGS+=	--with-pcctsinc=${PREFIX}/include/pccts
CONFIGURE_ARGS+=	--with-gtkmm-exec-prefix=/dev/null
# don't pick up an installed libcdda_paranoia
LDFLAGS+=		-L../paranoia

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-posix-threads
.endif

#override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""

USE_BUILDLINK3=	yes

post-configure:
	cd ${WRKSRC}/scsilib/RULES ; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${MACHINE}-netbsd-cc.rul;

post-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cdrdao
		${INSTALL_MAN} ${WRKSRC}/README \
			${WRKSRC}/README.PlexDAE \
			${PREFIX}/share/doc/cdrdao
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cdrdao/testtocs
		${INSTALL_MAN} ${WRKSRC}/testtocs/*.toc \
			${PREFIX}/share/doc/cdrdao/testtocs
		${INSTALL_MAN_DIR} ${PREFIX}/share/examples/cdrdao
		${INSTALL_MAN} ${WRKSRC}/contrib/mp32dao/mp32dao.pl \
			${PREFIX}/share/examples/cdrdao
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

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/pccts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
