# $NetBSD: Makefile,v 1.6 2002/10/07 14:43:08 hubertf Exp $

DISTNAME=	pkg_tarup-1.1
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

# Set SCRIPT_SUBST to substitute "${variable}" to "value" in MESSAGE
SCRIPT_SUBST+=	AWK=${AWK}				\
		ECHO=${ECHO}				\
		ID=${ID}				\
		PKG_DBDIR=${PKG_DBDIR}			\
		PKG_SUFX=${PKG_SUFX}			\
		PREFIX=${PREFIX}			\
		SH=${SH}				\
		SU=${SU}

# XXX this should probably use the @VAR@ form instead of ${VAR}...
SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}

do-configure:
	${SED} ${SCRIPT_SUBST_SED}			\
			< ${FILESDIR}/pkg_tarup		\
			> ${WRKSRC}/pkg_tarup		\

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
