# $NetBSD: Makefile,v 1.7 2003/06/02 01:21:20 jschauma Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

GNU_CONFIGURE=	yes

CPPFLAGS+=	`${AWK} -F: '/^uucp:/ { 				\
		printf(\"-DDAEMONUSER=%s -DDAEMONGROUP=%s\", $$3, $$4); }' \
		/etc/passwd`

.include "../../mk/bsd.pkg.mk"
