# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:28 jlam Exp $
#

DISTNAME=	check_cluster
PKGNAME=	netsaint-plugin-cluster-20001207
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/alpha/
EXTRACT_SUFX=	.c

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://netsaint.sourceforge.net/
COMMENT=	host and service cluster plugin for NetSaint

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base

EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CPPFLAGS} ${CFLAGS} -o check_cluster check_cluster.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_cluster ${PREFIX}/libexec/netsaint

.include "../../mk/bsd.pkg.mk"
