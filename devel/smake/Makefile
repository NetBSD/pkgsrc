# $NetBSD: Makefile,v 1.20 2021/11/21 14:09:19 ryoon Exp $

DISTNAME=	schily-2021-09-18
PKGNAME=	smake-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	Highly portable UNIX make implementation
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no
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
