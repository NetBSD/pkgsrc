# $NetBSD: Makefile,v 1.3 2001/10/31 14:36:41 tv Exp $

DISTNAME=	bchunk-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hes.iki.fi/bchunk/

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://hes.iki.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk

.include "../../mk/bsd.pkg.mk"
