# $NetBSD: Makefile,v 1.8 2002/11/23 22:47:02 wiz Exp $

DISTNAME=	pkg_tarup-1.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Generates binary package from installed pkg

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_BUILD=	yes
NO_MTREE=	yes

# Set SCRIPT_SUBST to substitute "@VARIABLE@" with "value"
SCRIPT_SUBST+=	AWK=${AWK:Q}				\
		ECHO=${ECHO:Q}				\
		ID=${ID:Q}				\
		PKG_DBDIR=${PKG_DBDIR:Q}		\
		PKG_SUFX=${PKG_SUFX:Q}			\
		PREFIX=${PREFIX:Q}			\
		PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
		SH=${SH:Q}				\
		SU=${SU:Q}

SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-configure:
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup		\
			> ${WRKSRC}/pkg_tarup		\

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
