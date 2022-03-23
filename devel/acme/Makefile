# $NetBSD: Makefile,v 1.19 2022/03/23 13:31:07 wiz Exp $
#

DISTNAME=	acme-crossass-code-0-r323-trunk
PKGNAME=	acme-0.97.0.0.323
CATEGORIES=	devel
#MASTER_SITES=	https://sourceforge.net/code-snapshots/svn/a/ac/acme-crossass/code-0/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/acme-crossass/
COMMENT=	Cross assembler for 6502, 65c02, and 65816
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax unzip

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_DIRS=	src

ACME_LIB=	${PREFIX}/share/acme
MAKE_ENV+=	ACME_LIB=${ACME_LIB:Q}

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/acme
INSTALLATION_DIRS+=	share/doc/acme

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/acme ${DESTDIR}${PREFIX}/bin/acme
	cd ${WRKSRC}/docs && pax -rw . ${DESTDIR}${PREFIX}/share/doc/acme
	cd ${WRKSRC}/ACME_Lib && pax -rw . ${DESTDIR}${ACME_LIB}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Extra data overflow: Need 24 bytes but only found 20 bytes
TOOLS_PLATFORM.unzip=
.endif

.include "../../mk/bsd.pkg.mk"
