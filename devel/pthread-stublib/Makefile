# $NetBSD: Makefile,v 1.5 2018/08/19 20:16:39 wiz Exp $

DISTNAME=	pthread-stublib-1.0
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library providing noop-stubs for pthread functions

WRKSRC=		${WRKDIR}
USE_LIBTOOL=	yes

ONLY_FOR_PLATFORM= NetBSD-[12].*-*

INSTALLATION_DIRS=	lib

do-extract:
	${CP} ${FILESDIR}/pthread-stubs.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
