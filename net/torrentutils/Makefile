# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:47:34 wiz Exp $
#

DISTNAME=		torrentutils-0.3.0
CATEGORIES=		net
MASTER_SITES=		http://www.student.lu.se/~nbi98oli/src/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.student.lu.se/~nbi98oli/src/
COMMENT=		Manage BitTorrent files and interact with trackers

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make
USE_PERL5=		yes

REPLACE_PERL=		torrenttool.in

.include "../../mk/bsd.pkg.mk"
