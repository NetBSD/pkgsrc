# $NetBSD: Makefile,v 1.11 2005/03/19 16:02:46 tv Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	YES

CONFIGURE_ENV+=	MKDIR_PATH=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
