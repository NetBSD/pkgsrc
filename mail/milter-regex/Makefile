# $NetBSD: Makefile,v 1.2 2004/02/21 07:12:50 snj Exp $
#

DISTNAME=	milter-regex-0.6
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/milter-regex.html
COMMENT=	Milter enabling regular expression filtering

USE_BUILDLINK2=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
