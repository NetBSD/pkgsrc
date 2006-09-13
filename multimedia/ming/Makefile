# $NetBSD: Makefile,v 1.3 2006/09/13 15:53:51 obache Exp $
#

DISTNAME=		ming-0.3.0
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ming/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Create SWF (Macromedia Flash) files with this library

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
