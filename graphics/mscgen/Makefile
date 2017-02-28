# $NetBSD: Makefile,v 1.14 2017/02/28 15:20:05 ryoon Exp $
#

DISTNAME=		mscgen-src-0.20
PKGNAME=		${DISTNAME:S/-src-/-/}
PKGREVISION=		10
CATEGORIES=		devel graphics
MASTER_SITES=		http://www.mcternan.me.uk/mscgen/software/

MAINTAINER=		jan.m.danielsson@gmail.com
HOMEPAGE=		http://www.mcternan.me.uk/mscgen/
COMMENT=		Tool for drawing call sequence graphs
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
