# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:13 jmmv Exp $
#

DISTNAME=	randread-0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	program to help benchmark random disk read performance

ALL_TARGET=	randread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/randread ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
