# $NetBSD: Makefile,v 1.2 2001/09/09 20:36:39 agc Exp $
#

DISTNAME=	check_cluster
PKGNAME=	netsaint-plugin-cluster-20001207
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/alpha/
EXTRACT_SUFX=	.c

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://netsaint.sourceforge.net/
COMMENT=	host and service cluster plugin for NetSaint

DEPENDS+=	netsaint-base-*:../../net/netsaint-base

EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CPPFLAGS} ${CFLAGS} -o check_cluster check_cluster.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_cluster ${PREFIX}/libexec/netsaint

.include "../../mk/bsd.pkg.mk"
