# $NetBSD: Makefile,v 1.23 2001/06/18 05:17:14 jlam Exp $
#

DISTNAME=	xpkgwedge-1.2
CATEGORIES=	pkgtools devel x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	allows X11 pkgs to be built and used outside of /usr/X11R6

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	# defined
NO_WRKSUBDIR=	# defined
NO_CHECKSUM=	# defined

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

pre-extract:
	@if [ ! -f ${X11BASE}/include/X11/X.h ]; then \
		${ECHO} 'xpkgwedge requires $$X11BASE to point to the real X distribution.'; \
		${ECHO} 'If you are setting this variable in mk.conf, fix or remove the setting'; \
		${ECHO} 'and then install xpkgwedge.'; \
		${FALSE}; \
	fi

do-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/pkgxmkmf.in > ${WRKDIR}/pkgxmkmf

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/config
	${INSTALL_DATA} ${FILESDIR}/xpkgwedge.def ${PREFIX}/lib/X11/config
	${INSTALL_SCRIPT} ${WRKSRC}/pkgxmkmf ${PREFIX}/bin/pkgxmkmf

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"

# Clear the build dependencies list so that xpkgwedge will not be recursively
# dependent on itself.
BUILD_DEPENDS=
