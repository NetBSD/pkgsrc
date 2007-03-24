# $NetBSD: Makefile,v 1.11 2007/03/24 19:21:23 joerg Exp $
#

DISTNAME=	golddigC3.0
PKGNAME=	golddig-3.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast action game designed for use with X

USE_X11BASE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-build:
	for f in ${WRKSRC}/golddig.6 ${WRKSRC}/gdedit.6; do \
		${SED} "s|@PREFIX@|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
