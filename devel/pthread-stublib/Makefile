# $NetBSD: Makefile,v 1.3 2009/04/09 00:48:08 joerg Exp $

DISTNAME=	pthread-stublib-1.0
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Library providing noop-stubs for pthread functions

WRKSRC=		${WRKDIR}
USE_LIBTOOL=	yes

ONLY_FOR_PLATFORM= NetBSD-[12].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	lib

do-extract:
	${CP} ${FILESDIR}/pthread-stubs.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
