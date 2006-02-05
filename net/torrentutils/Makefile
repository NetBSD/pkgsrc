# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:31 joerg Exp $
#

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://www.student.lu.se/~nbi98oli/src/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.student.lu.se/~nbi98oli/src/
COMMENT=		Manage BitTorrent files and interact with trackers

DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_TOOLS+=		gmake perl:run
REPLACE_PERL=		torrenttool.in

post-build:
	${SED} "s!/bin/sh!${PREFIX}/bin/bash!" ${WRKSRC}/defrag \
		> ${WRKSRC}/defrag.patched && \
	${MV} ${WRKSRC}/defrag.patched ${WRKSRC}/defrag

.include "../../mk/bsd.pkg.mk"
