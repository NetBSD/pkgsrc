# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:10 wiz Exp $

DISTNAME=	bchunk-1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hes.iki.fi/bchunk/

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://hes.iki.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk

.include "../../mk/bsd.pkg.mk"
