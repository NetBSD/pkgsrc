# $NetBSD: Makefile,v 1.18 2019/10/04 18:02:48 nia Exp $

DISTNAME=	advancecomp-2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=amadvance/}
GITHUB_PROJECT=	advancecomp
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.advancemame.it/comp-readme
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++03

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-features=extensions
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
