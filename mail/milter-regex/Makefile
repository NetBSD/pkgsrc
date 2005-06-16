# $NetBSD: Makefile,v 1.10 2005/06/16 06:58:03 jlam Exp $
#

DISTNAME=	milter-regex-1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	jdarrow@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/milter-regex.html
COMMENT=	Milter enabling regular expression filtering

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
