# $NetBSD: Makefile,v 1.2 2006/05/22 15:10:38 joerg Exp $
#

DISTNAME=		nload-0.6.0
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nload/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.roland-riegel.de/nload/
COMMENT=		Monitoring network traffic and bandwidth usage

USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
