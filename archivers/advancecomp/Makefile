# $NetBSD: Makefile,v 1.6 2005/01/21 20:57:54 tv Exp $

DISTNAME=	advancecomp-1.13
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
GCC_REQD+=		3.3.4 # base g++ iostream has no "long long" support
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
