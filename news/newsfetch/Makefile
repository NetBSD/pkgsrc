# $NetBSD: Makefile,v 1.12 2016/02/25 16:30:31 jperkin Exp $
#

DISTNAME=	newsfetch-1.3
PKGREVISION=	2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jay.fink@gmail.com
HOMEPAGE=	http://www.systhread.net/coding
COMMENT=	Downloads newsgroup messages in mail file format

WRKSRC=		${WRKDIR}/newsfetch

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
