# $NetBSD: Makefile,v 1.2 2021/06/25 13:50:45 micha Exp $

DISTNAME=	schily-2021-06-07
PKGNAME=	mdigest-1.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	Calculates a message digest
LICENSE=	cddl-1.0 AND 2-clause-bsd AND mit AND public-domain

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
	cd ${WRKSRC} && for library in libschily libmdigest ;		\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/mdigest && ${SMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/mdigest && ${SMAKE} ${MAKE_FLAGS} install

.include "../../mk/bsd.pkg.mk"
