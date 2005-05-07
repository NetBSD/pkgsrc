# $NetBSD: Makefile,v 1.67 2005/05/07 22:24:04 wiz Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in buildlink3.mk to the correct version,
#	usually the most recent.

DISTNAME=	x11-links-0.24
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Shadow tree of links to native X11 headers and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_MTREE=		yes
USE_X11=		yes

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PLIST_SRC.dirs=		${PLIST_SRC}.dirs
PLIST_SRC.files=	${PLIST_SRC}.files

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/X.h)
PKG_FAIL_REASON=	"${PKGNAME} requires X headers to be installed"
.endif

.if ${OPSYS} == "IRIX"
.  include "xsgi.mk"
.elif ${OPSYS} == "OSF1"
.  include "xdec.mk"
.elif !empty(X11BASE:M*openwin)
.  include "openwin.mk"
.else
.  include "xfree.mk"
.endif

X11_LINKS_SUBDIR=	share/x11-links
X11_LINKS_BUILD_DIR=	${WRKSRC}/${X11_LINKS_SUBDIR}
X11_LINKS_DIR=		${PREFIX}/${X11_LINKS_SUBDIR}

FILES_LIST_CMD=	${SED} -e "s/@ABI@/${ABI}/" ${FILES_LIST} | ${GREP} -v "^\#"

CREATE_X11LINK?=	${LN} -fs $$src $$dest

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
		if ${TEST} -r ${X11BASE}/$$file; then			\
			src="${X11BASE}/$$file";			\
			dest="${X11_LINKS_BUILD_DIR}/$$file";		\
			${CREATE_X11LINK};				\
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
