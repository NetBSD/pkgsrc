# $NetBSD: Makefile,v 1.19 2004/04/20 16:26:07 wiz Exp $

DISTNAME=	pkg_tarup-1.5.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Generates binary package(s) from installed pkg(s)

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

# Set SCRIPT_SUBST to substitute "@VARIABLE@" with "value"
SCRIPT_SUBST+=	AWK=${AWK:Q}				\
		ECHO=${ECHO:Q}				\
		HEAD=${HEAD:Q}				\
		ID=${ID:Q}				\
		PKG_DBDIR=${PKG_DBDIR:Q}		\
		PKG_SUFX=${PKG_SUFX:Q}			\
		PREFIX=${PREFIX:Q}			\
		PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
		SH=${SH:Q}				\
		SU=${SU:Q}

SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

INSTALLATION_DIRS=	bin

do-configure:
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup		\
			> ${WRKSRC}/pkg_tarup
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup_all	\
			> ${WRKSRC}/pkg_tarup_all

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup_all ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
