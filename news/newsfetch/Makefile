# $NetBSD: Makefile,v 1.11 2012/10/08 12:27:41 asau Exp $
#

DISTNAME=	newsfetch-1.3
PKGREVISION=	2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jay.fink@gmail.com
HOMEPAGE=	http://www.systhread.net/coding
COMMENT=	Downloads newsgroup messages in mail file format

WRKSRC=		${WRKDIR}/newsfetch

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
