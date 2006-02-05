# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:27 joerg Exp $
#

DISTNAME=	check_cluster
PKGNAME=	netsaint-plugin-cluster-20001207
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/alpha/
EXTRACT_SUFX=	.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://netsaint.sourceforge.net/
COMMENT=	Host and service cluster plugin for NetSaint

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	libexec/netsaint

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CPPFLAGS} ${CFLAGS} -o check_cluster check_cluster.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_cluster ${PREFIX}/libexec/netsaint

.include "../../mk/bsd.pkg.mk"
