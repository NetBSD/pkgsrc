# $NetBSD: Makefile,v 1.8 2009/04/16 17:00:31 jrf Exp $
#

DISTNAME=	newsfetch-1.3
PKGREVISION=	1
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

.include "../../mk/bsd.pkg.mk"
