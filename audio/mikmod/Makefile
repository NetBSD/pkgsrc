# $NetBSD: Makefile,v 1.25 2001/06/19 16:04:18 jlam Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.darkorb.net/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
#USE_CURSES=		yes

USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../audio/libmikmod/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
