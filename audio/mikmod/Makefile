# $NetBSD: Makefile,v 1.29 2003/07/13 13:50:27 wiz Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mikmod.org/files/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://www.mikmod.org/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
