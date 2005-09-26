# $NetBSD: Makefile,v 1.26 2005/09/26 01:01:46 fredb Exp $

.include "../../sysutils/cdrdao/Makefile.common"

PKGREVISION=		3

PKGNAME=		cdrdao-${CDRDAO_VER}

COMMENT=		Records audio or data CD-Rs in disk-at-once (DAO) mode

CONFIGURE_ARGS+=	--without-xdao

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-posix-threads
.endif    

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
			${WRKSRC}/contrib/psxcopy-0.2/psxdump.c \
			${WRKSRC}/contrib/psxcopy-0.2/read-psx \
			${WRKSRC}/contrib/psxcopy-0.2/write-psx \
			${PREFIX}/share/examples/cdrdao/psxcopy
		${INSTALL_MAN} ${WRKSRC}/contrib/wav2dao/wav2dao.pl \
			${PREFIX}/share/examples/cdrdao

.include "../../mk/pthread.buildlink3.mk" 
.include "../../mk/bsd.pkg.mk"
