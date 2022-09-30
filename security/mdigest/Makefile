# $NetBSD: Makefile,v 1.4 2022/09/30 15:40:26 micha Exp $

DISTNAME=	2022-09-18
PKGNAME=	mdigest-1.10
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/schilytools/schilytools/archive/
DIST_SUBDIR=	schilytools

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://codeberg.org/schilytools/schilytools/
COMMENT=	Calculates a message digest
LICENSE=	cddl-1.0 AND 2-clause-bsd AND mit AND public-domain

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
	cd ${WRKSRC} && for library in libschily libmdigest ;		\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/mdigest && ${SMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/mdigest && ${SMAKE} ${MAKE_FLAGS} install

.include "../../mk/bsd.pkg.mk"
