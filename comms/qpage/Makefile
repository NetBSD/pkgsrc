# $NetBSD: Makefile,v 1.8 2003/07/17 21:26:59 grant Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

GNU_CONFIGURE=	yes

CPPFLAGS+=	`${AWK} -F: '/^uucp:/ { 				\
		printf(\"-DDAEMONUSER=%s -DDAEMONGROUP=%s\", $$3, $$4); }' \
		/etc/passwd`

.include "../../mk/bsd.pkg.mk"
