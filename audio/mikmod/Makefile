# $NetBSD: Makefile,v 1.40 2005/05/22 20:07:38 jlam Exp $

DISTNAME=	mikmod-3.2.1
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://mikmod.raphnet.net/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
