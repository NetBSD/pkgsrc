# $NetBSD: Makefile,v 1.29 2022/06/28 11:35:21 wiz Exp $

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		15
CATEGORIES=		net
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://oskarsapps.mine.nu/torrentutils.html
COMMENT=		Manage BitTorrent files and interact with trackers
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

USE_TOOLS+=		bash:run gmake perl:run
REPLACE_BASH+=		defrag.in
REPLACE_PERL=		torrenttool.in
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
