# $NetBSD: Makefile,v 1.5 2003/09/22 21:12:17 wiz Exp $
#

DISTNAME=	newsfetch-1.3
WRKSRC=		${WRKDIR}/newsfetch
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jrf@diverge.org
HOMEPAGE=	# doesn't work anymore - http://www.diverge.org/jrf/
COMMENT=	Downloads newsgroup messages in mail file format

USE_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
