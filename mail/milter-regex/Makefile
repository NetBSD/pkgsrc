# $NetBSD: Makefile,v 1.4 2004/04/06 13:50:57 tv Exp $
#

DISTNAME=	milter-regex-1.2
PKGREVISION=	1
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
