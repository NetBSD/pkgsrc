# $NetBSD: Makefile,v 1.7 2004/03/29 17:31:54 tv Exp $
#

DISTNAME=	newsfetch-1.3
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jrf@diverge.org
HOMEPAGE=	# doesn't work anymore - http://www.diverge.org/jrf/
COMMENT=	Downloads newsgroup messages in mail file format

WRKSRC=		${WRKDIR}/newsfetch

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
