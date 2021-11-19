# $NetBSD: Makefile,v 1.2 2021/11/19 11:41:23 micha Exp $

DISTNAME=	schily-2021-09-18
PKGNAME=	tartest-1.24
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	Test tar archive for POSIX.1-1990 compliance
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.3nb11:../../devel/smake
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
