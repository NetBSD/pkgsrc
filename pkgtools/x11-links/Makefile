# $NetBSD: Makefile,v 1.40 2003/09/19 01:29:00 grant Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in mk/buildlink[23]/bsd.buildlink[23].mk
#	to the correct version, usually the most recent.

DISTNAME=	x11-links-0.14
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Shadow tree of links to ${X11BASE} headers and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_MTREE=		yes
USE_X11=		yes
USE_X11_LINKS=		no

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PLIST_SRC.dirs=		${PLIST_SRC}.dirs
PLIST_SRC.files=	${PLIST_SRC}.files

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/X.h)
PKG_FAIL_REASON=	"${PKGNAME} requires X headers to be installed"
.endif

.if ${OPSYS} == "IRIX"
.  include "xsgi.mk"
.elif !empty(X11BASE:M*openwin)
.  include "openwin.mk"
.else
.  include "xfree.mk"
.endif

X11_LINKS_SUBDIR=	share/x11-links
X11_LINKS_BUILD_DIR=	${WRKSRC}/${X11_LINKS_SUBDIR}
X11_LINKS_DIR=		${PREFIX}/${X11_LINKS_SUBDIR}

FILES_LIST_CMD=	${CAT} ${FILES_LIST} | ${GREP} -v "^\#"

do-build:
	${MKDIR} ${X11_LINKS_BUILD_DIR}
	${RM} -f ${PLIST_SRC.dirs}
	${FILES_LIST_CMD} | ${SED} -e "s,/[^/]*$$,," | ${SORT} -u |	\
	while read dir; do						\
		if [ -d ${X11BASE}/$$dir ]; then			\
			${MKDIR} ${X11_LINKS_BUILD_DIR}/$$dir;		\
			${ECHO} "@dirrm ${X11_LINKS_SUBDIR}/$$dir"	\
				>> ${PLIST_SRC.dirs};			\
		fi;							\
	done
	${RM} -f ${PLIST_SRC.files}
	${FILES_LIST_CMD} | ${SORT} -u |				\
	while read file; do						\
		if ${TEST} -e ${X11BASE}/$$file; then			\
			${LN} -fs ${X11BASE}/$$file			\
				${X11_LINKS_BUILD_DIR}/$$file;		\
			${ECHO} "${X11_LINKS_SUBDIR}/$$file"		\
				>> ${PLIST_SRC.files};			\
		fi;							\
	done

post-build:
	( ${CAT} ${PKGDIR}/PLIST;					\
	  ${SORT} -u ${PLIST_SRC.files};				\
	  ${SORT} -ur ${PLIST_SRC.dirs};				\
	  ${ECHO} "@dirrm ${X11_LINKS_SUBDIR}";				\
	) > ${PLIST_SRC}

do-install:
	${INSTALL_DATA_DIR} ${X11_LINKS_DIR}
	cd ${X11_LINKS_BUILD_DIR} && ${PAX} -rwpp . ${X11_LINKS_DIR}

.include "../../mk/bsd.pkg.mk"
