# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 08:10:58 shell Exp $

DISTNAME=	dnetc-netbsd-i386-elf
PKGNAME=	dnetc-2.8015.469
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/current-client/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.distributed.net/
COMMENT=	official distributed.net client

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=	YES

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; ${GTAR} -zxf ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnetc/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/dnetc/
	${INSTALL_MAN} ${WRKSRC}/dnetc.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
