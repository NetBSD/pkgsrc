# $NetBSD: Makefile,v 1.3 2003/08/28 04:13:10 jmc Exp $
#

DISTNAME=	ser-0.8.10_src
PKGNAME=	ser-0.8.10
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/latest/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.iptel.org/ser/
COMMENT=	SIP express router

WRKSRC=		${WRKDIR}/ser-0.8.10

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

MAKE_ENV+= BUILDLINK_PREFIX.pthread="${BUILDLINK_PREFIX.pthread}"

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
