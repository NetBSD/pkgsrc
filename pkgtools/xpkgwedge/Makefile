# $NetBSD: Makefile,v 1.15 2000/10/23 17:32:07 jlam Exp $
#

DISTNAME=	xpkgwedge-1.0
CATEGORIES=	pkgtools devel x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Documentation/netbsd/Packages.txt

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	# defined
NO_WRKSUBDIR=	# defined
NO_CHECKSUM=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE

pre-extract:
	@if [ ! -f ${X11BASE}/include/X11/X.h ]; then \
		${ECHO} 'xpkgwedge requires $$X11BASE to point to the real X distribution.'; \
		${ECHO} 'If you are setting this variable in mk.conf, fix or remove the setting'; \
		${ECHO} 'and then install xpkgwedge.'; \
		${FALSE}; \
	fi

do-build:
	${SED}  -e "s,@X11BASE@,${X11BASE},g" \
		-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/pkgxmkmf.in > ${WRKDIR}/pkgxmkmf

post-build:
	${SED}	-e "s,@X11BASE@,${X11BASE},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@X11BASE@,${X11BASE},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE.pre > ${MESSAGE_FILE}

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
