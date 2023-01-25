# $NetBSD: Makefile,v 1.23 2023/01/25 16:04:26 micha Exp $

DISTNAME=	2023-01-12
PKGNAME=	smake-1.7
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/schilytools/schilytools/archive/
DIST_SUBDIR=	schilytools

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://codeberg.org/schilytools/schilytools/
COMMENT=	Highly portable UNIX make implementation
LICENSE=	cddl-1.0

MAKE_FLAGS+=	GMAKE_NOWARN=true

USE_TOOLS+=	gmake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

# Platform specific code (for sharing with other packages based on schilytools)
.include "Makefile.common"

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	smake/smake.1
SUBST_SED.man=		-e "s,/opt/schily/share/lib/smake/defaults.smk,${PREFIX}/share/lib/smake/defaults.smk,g"
SUBST_MESSAGE.man=	Fix path for default rules in manpage.

BUILD_DIRS=	libschily
BUILD_DIRS+=	smake
INSTALL_DIRS=	smake

do-configure:
	cd ${WRKSRC}/inc && ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
