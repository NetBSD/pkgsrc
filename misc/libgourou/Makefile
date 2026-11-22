# $NetBSD: Makefile,v 1.1 2026/11/22 14:59:41 wiz Exp $

DISTNAME=	v0.9
PKGNAME=	libgourou-${DISTNAME:S/v//g}
CATEGORIES=	misc
MASTER_SITES=	https://forge.soutade.fr/soutade/libgourou/archive/
DIST_SUBDIR=	libgourou

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.soutade.fr/soutade/libgourou/
COMMENT=	Free implementation of Adobe's ADEPT protocol
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libgourou
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	UPDFPARSERLIB=${BUILDLINK_PREFIX.uPDFParser}/lib/libupdfparser.so
MAKE_FLAGS+=	MANDIR=/${PKGMANDIR}

REPLACE_SH+=	scripts/setup.sh

INSTALLATION_DIRS+=	share/doc/libgourou

# work around for using pkgsrc udfparser library
pre-build:
	${MKDIR} -p ${WRKSRC}/lib/updfparser

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/libgourou

.include "../../archivers/libzip/buildlink3.mk"
.include "../../print/uPDFParser/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
