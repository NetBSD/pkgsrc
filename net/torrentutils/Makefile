# $NetBSD: Makefile,v 1.11 2006/10/04 21:53:18 wiz Exp $
#

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://oskarsapps.mine.nu/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oskarsapps.mine.nu/torrentutils.html
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
