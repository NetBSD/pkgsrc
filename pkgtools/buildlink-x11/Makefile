# $NetBSD: Makefile,v 1.1.1.1 2001/07/02 21:00:44 jlam Exp $

DISTNAME=	buildlink-x11-0.4
CATEGORIES=	pkgtools devel x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	allows X11 pkgs to be built using the buildlink.mk infrastructure

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined
USE_X11BASE=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
DEPENDS+=	diffutils>=2.7:../../devel/diffutils
DIFF=		${LOCALBASE}/bin/gdiff
.else
DIFF=		/usr/bin/diff
.endif

FILES_SUBST=		X11BASE=${X11BASE}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		DIFF=${DIFF:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/config
	${INSTALL_DATA} ${FILESDIR}/buildlinkX11.def ${PREFIX}/lib/X11/config
	${INSTALL_DATA} ${FILESDIR}/buildlinkX11.rules ${PREFIX}/lib/X11/config

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
