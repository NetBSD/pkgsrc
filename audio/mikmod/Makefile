# $NetBSD: Makefile,v 1.32 2004/01/17 19:45:37 kristerw Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.raphnet.net/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
