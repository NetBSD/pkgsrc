# $NetBSD: Makefile,v 1.9 2006/03/04 21:28:51 jlam Exp $

DISTNAME=	advancecomp-1.13
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
