# $NetBSD: Makefile,v 1.33 2008/02/06 22:39:43 joerg Exp $

DISTNAME=	pkg_tarup-1.7
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Generates binary package(s) from installed pkg(s)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_LANGUAGES=	# none

# Set SCRIPT_SUBST to substitute "@VARIABLE@" with "value"
SCRIPT_SUBST+=	\
		ECHO=${ECHO:Q}				\
		ECHO_N=${ECHO_N:Q}			\
		GREP=${GREP:Q}				\
		HEAD=${HEAD:Q}				\
		ID=${ID:Q}				\
		PKG_DBDIR=${PKG_DBDIR:Q}		\
		PKG_SUFX=${PKG_SUFX:Q}			\
		PREFIX=${PREFIX:Q}			\
		PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
		ROOT_USER=${REAL_ROOT_USER:Q}		\
		SED=${SED:Q}				\
		SH=${SH:Q}				\
		SU_CMD=${SU_CMD:Q}			\
		XARGS=${XARGS:Q}

SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

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
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup_all ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg_tarup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
