# $NetBSD: Makefile,v 1.5 2001/03/19 20:00:06 wiz Exp $
#

DISTNAME=	golddigC3.0
PKGNAME=	golddig-3.0
CATEGORIES=	games x11
MASTER_SITES=	http://www.netbsd.org/~chuck/gz/

MAINTAINER=	wiz@netbsd.org
COMMENT=	Fast action game designed for use with X

USE_X11BASE=	yes

post-build:
	for f in ${WRKSRC}/golddig.6 ${WRKSRC}/gdedit.6; do \
		${SED} "s|@PREFIX@|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

.include "../../mk/bsd.pkg.mk"
