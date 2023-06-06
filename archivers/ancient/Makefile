# $NetBSD: Makefile,v 1.2 2023/06/06 12:40:15 riastradh Exp $

DISTNAME=	ancient-2.0.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=temisu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/temisu/ancient
COMMENT=	Decompression routines for ancient formats
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake autoconf pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
