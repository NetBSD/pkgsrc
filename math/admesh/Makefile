# $NetBSD: Makefile,v 1.14 2025/10/06 07:56:40 wiz Exp $

DISTNAME=		admesh-0.98.5
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=admesh/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://admesh.readthedocs.io/en/latest/
COMMENT=		Program for processing triangulated solid meshes
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	share/examples/admesh
USE_LIBTOOL=		yes
USE_TOOLS+=		autoheader automake autoreconf
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	libadmesh.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/block.stl \
		${DESTDIR}${PREFIX}/share/examples/admesh

.include "../../mk/bsd.pkg.mk"
