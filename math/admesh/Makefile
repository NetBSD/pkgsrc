# $NetBSD: Makefile,v 1.13 2025/10/04 17:15:36 kikadf Exp $

DISTNAME=		admesh-0.98.5
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=admesh/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://admesh.readthedocs.io/en/latest/
COMMENT=		Program for processing triangulated solid meshes
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	share/doc/admesh
INSTALLATION_DIRS+=	share/examples/admesh
USE_TOOLS+=		autoheader automake autoreconf
USE_LANGUAGES=		c

pre-configure:
	cd ${WRKSRC} && \
		${SED} -i.bak -e '/git/d' \
			-e '/fortag/d' Makefile.am && \
		${SH} ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/admesh ${DESTDIR}${PREFIX}/bin
.for lib in libadmesh.so libadmesh.so.1 libadmesh.so.1.0
	${INSTALL_LIB} ${WRKSRC}/.libs/${lib} ${DESTDIR}${PREFIX}/lib
.endfor
	cd ${WRKSRC} && ${INSTALL_DATA} README.md admesh-doc.txt \
		${DESTDIR}${PREFIX}/share/doc/admesh
	${INSTALL_DATA} ${WRKSRC}/block.stl \
		${DESTDIR}${PREFIX}/share/examples/admesh


.include "../../mk/bsd.pkg.mk"
