# $NetBSD: Makefile,v 1.27 2001/10/22 03:47:28 mycroft Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://www.mikmod.org/files/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://www.mikmod.org/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../audio/libmikmod/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
