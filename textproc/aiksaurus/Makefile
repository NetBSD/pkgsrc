# $NetBSD: Makefile,v 1.41 2023/11/12 13:23:40 wiz Exp $

DISTNAME=	aiksaurus-1.2.1
PKGREVISION=	17
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

# Fails with C++17 default in GCC 13.
# "error: ISO C++17 does not allow dynamic exception specifications"
FORCE_CXX_STD=	c++03

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
