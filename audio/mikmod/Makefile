# $NetBSD: Makefile,v 1.24 2001/06/11 06:34:18 jlam Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.darkorb.net/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files

DEPENDS+=	libmikmod>=3.1.9:../../audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_CURSES=	yes
REPLACE_NCURSES=	${WRKSRC}/configure

CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
