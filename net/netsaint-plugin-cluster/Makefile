# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:21 jlam Exp $
#

DISTNAME=	check_cluster
PKGNAME=	netsaint-plugin-cluster-20001207
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/alpha/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
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
