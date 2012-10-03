# $NetBSD: Makefile,v 1.17 2012/10/03 21:57:11 wiz Exp $

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://oskarsapps.mine.nu/torrentutils.html
COMMENT=		Manage BitTorrent files and interact with trackers
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_TOOLS+=		bash:run gmake perl:run
REPLACE_BASH+=		defrag.in
REPLACE_PERL=		torrenttool.in
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
