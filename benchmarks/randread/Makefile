# $NetBSD: Makefile,v 1.6 2004/07/30 15:50:38 minskim Exp $
#

DISTNAME=	randread-0.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	Program to help benchmark random disk read performance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ALL_TARGET=	randread
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/randread ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
