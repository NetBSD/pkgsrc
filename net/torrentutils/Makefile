# $NetBSD: Makefile,v 1.14 2007/06/22 17:46:19 tron Exp $

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://oskarsapps.mine.nu/torrentutils.html
COMMENT=		Manage BitTorrent files and interact with trackers

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_TOOLS+=		bash:run gmake perl:run
REPLACE_BASH+=		defrag.in
REPLACE_PERL=		torrenttool.in
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
