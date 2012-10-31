# $NetBSD: Makefile,v 1.4 2012/10/31 11:19:27 asau Exp $

DISTNAME=	pthread-stublib-1.0
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Library providing noop-stubs for pthread functions

WRKSRC=		${WRKDIR}
USE_LIBTOOL=	yes

ONLY_FOR_PLATFORM= NetBSD-[12].*-*

INSTALLATION_DIRS=	lib

do-extract:
	${CP} ${FILESDIR}/pthread-stubs.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
