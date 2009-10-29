# $NetBSD: Makefile,v 1.9 2009/10/29 22:40:23 tnn Exp $
#

DISTNAME=	newsfetch-1.3
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jay.fink@gmail.com
HOMEPAGE=	http://www.systhread.net/coding
COMMENT=	Downloads newsgroup messages in mail file format

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/newsfetch

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
