# $NetBSD: Makefile,v 1.56 2020/01/18 23:30:02 rillig Exp $

DISTNAME=	mikmod-3.2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mikmod.sourceforge.net/
COMMENT=	MOD player for UNI IT XM S3M MOD MTM STM DSM MED FAR ULT 669 files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
