# $NetBSD: Makefile,v 1.36 2015/12/29 05:06:06 dholland Exp $

.include "../../sysutils/cdrdao/Makefile.common"

PKGREVISION=	1

PKGNAME=		cdrdao-${CDRDAO_VER}

COMMENT=		Records audio or data CD-Rs in disk-at-once (DAO) mode

CONFIGURE_ARGS+=	--without-xdao

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-posix-threads
.endif

INSTALLATION_DIRS+=	share/doc/cdrdao/testtocs \
			share/examples/cdrdao/psxcopy

post-install:
		${INSTALL_MAN} ${WRKSRC}/README \
			${WRKSRC}/README.PlexDAE \
			${DESTDIR}${PREFIX}/share/doc/cdrdao
		${INSTALL_MAN} ${WRKSRC}/testtocs/*.toc \
			${DESTDIR}${PREFIX}/share/doc/cdrdao/testtocs
		${INSTALL_MAN} ${WRKSRC}/contrib/mp32dao/mp32dao.pl \
			${DESTDIR}${PREFIX}/share/examples/cdrdao
		${INSTALL_MAN} ${WRKSRC}/contrib/psxcopy-0.2/Makefile \
			${WRKSRC}/contrib/psxcopy-0.2/README \
			${WRKSRC}/contrib/psxcopy-0.2/cdjob.c \
			${WRKSRC}/contrib/psxcopy-0.2/psxdump.c \
			${WRKSRC}/contrib/psxcopy-0.2/read-psx \
			${WRKSRC}/contrib/psxcopy-0.2/write-psx \
			${DESTDIR}${PREFIX}/share/examples/cdrdao/psxcopy
		${INSTALL_MAN} ${WRKSRC}/contrib/wav2dao/wav2dao.pl \
			${DESTDIR}${PREFIX}/share/examples/cdrdao

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
