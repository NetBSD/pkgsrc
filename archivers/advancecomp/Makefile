# $NetBSD: Makefile,v 1.15 2014/10/09 14:05:50 wiz Exp $

DISTNAME=	advancecomp-1.15
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-features=extensions
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
