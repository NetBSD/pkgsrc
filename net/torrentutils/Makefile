# $NetBSD: Makefile,v 1.2 2004/03/08 09:06:39 wiz Exp $
#

DISTNAME=		torrentutils-0.3.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.student.lu.se/~nbi98oli/src/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.student.lu.se/~nbi98oli/src/
COMMENT=		Manage BitTorrent files and interact with trackers

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make
USE_PERL5=		yes

REPLACE_PERL=		torrenttool.in

.include "../../mk/bsd.pkg.mk"
