# $NetBSD: Makefile,v 1.18 2022/09/11 19:43:20 schmonz Exp $

DISTNAME=		goredo-1.27.1
CATEGORIES=		devel
MASTER_SITES=		http://www.goredo.cypherpunks.ru/download/
EXTRACT_SUFX=		.tar.zst

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.goredo.cypherpunks.ru/
COMMENT=		Go implementation of djb's redo
LICENSE=		gnu-gpl-v3

EXTRACT_USING=		bsdtar

WRKSRC=			${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS=	bin

do-build:
	${RUN} cd ${WRKSRC} && \
	${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} build -v -mod=vendor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/goredo ${DESTDIR}${PREFIX}/bin
	cd ${DESTDIR}${PREFIX}/bin && ./goredo -symlinks

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
