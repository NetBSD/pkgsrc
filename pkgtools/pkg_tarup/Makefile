# $NetBSD: Makefile,v 1.34 2008/02/12 15:03:28 rillig Exp $

DISTNAME=	pkg_tarup-1.7.1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Generates binary package(s) from installed pkg(s)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

# Set SCRIPT_SUBST to substitute "@VARIABLE@" with "value"
SUBST_CLASSES+=	tarup
SUBST_STAGE.tarup=	do-configure
SUBST_FILES.tarup=	pkg_tarup pkg_tarup_all pkg_tarup.1
SUBST_VARS.tarup=	ECHO ECHO_N GREP HEAD ID PKG_DBDIR PKG_SUFX PKG_TOOLS_BIN PREFIX SED SH SU_CMD XARGS
SUBST_SED.tarup=	-e 's,@ROOT_USER@,${REAL_ROOT_USER},g'

do-extract:
	cd ${FILESDIR} && cp pkg_tarup pkg_tarup.1 pkg_tarup_all ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_tarup_all ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg_tarup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
