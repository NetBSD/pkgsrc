# $NetBSD: Makefile,v 1.4 2003/07/21 16:31:04 martti Exp $
#

DISTNAME=	randread-0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	Program to help benchmark random disk read performance

ALL_TARGET=	randread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/randread ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
