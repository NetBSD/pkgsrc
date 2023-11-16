# $NetBSD: Makefile,v 1.13 2023/11/16 12:53:53 wiz Exp $

# Date of the latest git commit
DISTNAME=	adaptagrams-0.20231102
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjwybrow/}
GITHUB_TAG=	d00ce5936c12ec80e2070e894d9124fdc5ccd506

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adaptagrams.org/
COMMENT=	Tools for adaptive diagrams
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/adaptagrams-${GITHUB_TAG}/cola

USE_TOOLS+=		aclocal autoconf autoheader automake autoreconf pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
# Does not set -std=c++XX, but sigc++ (via cairomm) uses C++11 features in
# its headers.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	*/*.pc.in

TEST_TARGET=	check

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} -p m4 && autoreconf -fiv

.include "../../graphics/cairomm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
