# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:41 agc Exp $
#

DISTNAME=	newsfetch-1.3
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jrf@diverge.org
HOMEPAGE=	# doesn't work anymore - http://www.diverge.org/jrf/
COMMENT=	Downloads newsgroup messages in mail file format

WRKSRC=		${WRKDIR}/newsfetch
USE_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
