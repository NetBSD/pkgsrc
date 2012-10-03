# $NetBSD: Makefile,v 1.134.2.1 2012/10/03 12:09:12 spz Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in buildlink3.mk to the correct version,
#	usually the most recent.

DISTNAME=	x11-links-0.71
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Shadow tree of links to native X11 headers and libraries
LICENSE=	original-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NOT_FOR_PLATFORM=	DragonFly-*-*

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
USE_TOOLS+=		pax

PLIST_SRC.files=	${WRKDIR}/.PLIST_SRC.files
PLIST_SRC=		${.CURDIR}/PLIST ${PLIST_SRC.files}

OSVERSION_SPECIFIC=	yes

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
PKG_FAIL_REASON+=	"${PKGNAME} should only be used with X11_TYPE=native."
.elif !exists(${X11BASE}/include/X11/X.h)
PKG_FAIL_REASON+=	"pkgsrc has been configured to use a system provided X11 installation"
PKG_FAIL_REASON+=	"but one could not be found. Possible solutions:"
PKG_FAIL_REASON+=	""
PKG_FAIL_REASON+=	"	*) install X headers and libraries in X11BASE (currently ${X11BASE})"
PKG_FAIL_REASON+=	"	*) set X11_TYPE=modular in mk.conf to use X11 from pkgsrc"
PKG_FAIL_REASON+=	""
PKG_FAIL_REASON+=	"Please note that changing the value of X11_TYPE in existing"
PKG_FAIL_REASON+=	"pkgsrc installations is not supported!"
.endif

.if ${OPSYS} == "IRIX"
.  include "xsgi.mk"
.elif ${OPSYS} == "OSF1"
.  include "xdec.mk"
.elif !empty(X11BASE:M*openwin)
.  include "openwin.mk"
.elif exists(${X11BASE}/lib/X11/config/xorgversion.def) || \
      (exists(${X11BASE}/lib/X11/config/xorg.cf) && \
       exists(${X11BASE}/lib/X11/config/version.def)) || \
      exists(${X11BASE}/lib/pkgconfig/xorg-server.pc) || \
      exists(${X11BASE}/bin/Xquartz)
.  include "xorg.mk"
.else
.  include "xfree.mk"
.endif

X11_LINKS_SUBDIR=	share/x11-links
X11_LINKS_BUILD_DIR=	${WRKSRC}/${X11_LINKS_SUBDIR}
X11_LINKS_DIR=		${PREFIX}/${X11_LINKS_SUBDIR}

FILES_LIST_CMD=	${SED} -e "s/@ABI@/${ABI}/" ${FILES_LIST} | ${GREP} -v "^\#"

CREATE_X11LINK?=	${LN} -fs $$src $$dest

.include "../../mk/x11.buildlink3.mk"

do-build:
	${MKDIR} ${X11_LINKS_BUILD_DIR}
	${CHMOD} ${PKGDIRMODE} ${X11_LINKS_BUILD_DIR}
	${FILES_LIST_CMD} | ${SED} -e "s,/[^/]*$$,," | ${SORT} -u |	\
	while read dir; do						\
		if [ -d ${X11BASE}/$$dir ]; then			\
			${MKDIR} ${X11_LINKS_BUILD_DIR}/$$dir;		\
			${CHMOD} ${PKGDIRMODE} ${X11_LINKS_BUILD_DIR}/$$dir; \
		elif [ -d /usr/$$dir ]; then				\
			${MKDIR} ${X11_LINKS_BUILD_DIR}/$$dir;		\
			${CHMOD} ${PKGDIRMODE} ${X11_LINKS_BUILD_DIR}/$$dir; \
		fi;							\
	done
	${RM} -f ${PLIST_SRC.files}
	${FILES_LIST_CMD} | ${SORT} -u |				\
	while read file; do						\
		if ${TEST} -r ${X11BASE}/$$file; then			\
			src="${X11BASE}/$$file";			\
			dest="${X11_LINKS_BUILD_DIR}/$$file";		\
			${CREATE_X11LINK};				\
			${ECHO} "${X11_LINKS_SUBDIR}/$$file"		\
				>> ${PLIST_SRC.files};			\
		elif ${TEST} -r /usr/$$file; then			\
			src="/usr/$$file";				\
			dest="${X11_LINKS_BUILD_DIR}/$$file";		\
			${CREATE_X11LINK};				\
			${ECHO} "${X11_LINKS_SUBDIR}/$$file"		\
				>> ${PLIST_SRC.files};			\
		fi;							\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${X11_LINKS_DIR:Q}
	cd  ${X11_LINKS_BUILD_DIR} && \
		pax -rw .  ${DESTDIR:Q}${X11_LINKS_DIR:Q}

.include "../../mk/bsd.pkg.mk"
