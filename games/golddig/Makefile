# $NetBSD: Makefile,v 1.9 2006/06/15 13:31:29 wiz Exp $
#

DISTNAME=	golddigC3.0
PKGNAME=	golddig-3.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast action game designed for use with X

USE_X11BASE=	yes
.include "../../mk/x11.buildlink3.mk"

post-build:
	for f in ${WRKSRC}/golddig.6 ${WRKSRC}/gdedit.6; do \
		${SED} "s|@PREFIX@|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

.include "../../mk/bsd.pkg.mk"
