# $NetBSD: Makefile,v 1.23 2004/10/06 15:27:28 erh Exp $

DISTNAME=	pkg_tarup-1.6.3
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
SCRIPT_SUBST+=	\
		ECHO=${ECHO:Q}				\
		GREP=${GREP:Q}				\
		HEAD=${HEAD:Q}				\
		ID=${ID:Q}				\
		PKG_DBDIR=${PKG_DBDIR:Q}		\
		PKG_SUFX=${PKG_SUFX:Q}			\
		PREFIX=${PREFIX:Q}			\
		PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
		SED=${SED:Q}			\
		SH=${SH:Q}				\
		SU=${SU:Q}				\
		XARGS=${XARGS:Q}

SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

INSTALLATION_DIRS=	bin

do-configure:
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup		\
			> ${WRKSRC}/pkg_tarup
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup_all	\
			> ${WRKSRC}/pkg_tarup_all
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup.1   \
			> ${WRKSRC}/pkg_tarup.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup_all ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg_tarup.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
