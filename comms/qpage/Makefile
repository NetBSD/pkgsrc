# $NetBSD: Makefile,v 1.10 2005/03/03 15:13:39 wiz Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	MKDIR_PATH=${MKDIR:Q}

CPPFLAGS+=	${USERFLAGS}

.include "../../mk/bsd.pkg.mk"

USERFLAGS!=	${AWK} -F: '/^uucp:/ { printf("-DDAEMONUSER=%s -DDAEMONGROUP=%s", $$3, $$4); }' \
		/etc/passwd
