# $NetBSD: Makefile,v 1.12 2006/10/25 21:07:11 rillig Exp $
#

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		http://oskarsapps.mine.nu/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oskarsapps.mine.nu/torrentutils.html
COMMENT=		Manage BitTorrent files and interact with trackers

DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_TOOLS+=		bash:run gmake perl:run
REPLACE_BASH+=		defrag.in
REPLACE_PERL=		torrenttool.in
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
