# $NetBSD: Makefile,v 1.153 2016/01/28 19:11:30 abs Exp $

DISTNAME=	cpuflags-1.43
CATEGORIES=	devel sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu
LICENSE=	2-clause-bsd

# each OS needs explicit support (files/subr_*)
ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* SunOS-*-* FreeBSD-*-* Darwin-*-*

USE_LANGUAGES=	# empty
NO_CONFIGURE=	yes

MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	INSTALL_MAN=${INSTALL_MAN:Q}
MAKE_FLAGS+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
MAKE_FLAGS+=	INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}
MAKE_FLAGS+=	INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKE_FLAGS+=	INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

SUBST_CLASSES+=		cpuflags
SUBST_STAGE.cpuflags=	post-patch
SUBST_FILES.cpuflags=	cpuflags.sh
SUBST_SED.cpuflags=	-e s,@@SH@@,${SH:Q},

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/c* ${WRKSRC}
	${CP} ${FILESDIR}/o* ${WRKSRC}
	${CP} ${FILESDIR}/s* ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
