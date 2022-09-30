# $NetBSD: Makefile,v 1.3 2022/09/30 15:36:40 micha Exp $

DISTNAME=	2022-09-18
PKGNAME=	tartest-1.24
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://codeberg.org/schilytools/schilytools/archive/
DIST_SUBDIR=	schilytools

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://codeberg.org/schilytools/schilytools/
COMMENT=	Test tar archive for POSIX.1-1990 compliance
LICENSE=	cddl-1.0

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.6nb2:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in libschily ;			\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/tartest && ${SMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/tartest && ${SMAKE} ${MAKE_FLAGS} install

.include "../../mk/bsd.pkg.mk"
