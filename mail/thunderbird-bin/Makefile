# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 05:24:42 grant Exp $
#

DISTNAME=		# see Makefile.${OPSYS}.${ARCH}
PKGNAME=		thunderbird-bin-0.3
WRKSRC=			${WRKDIR}/thunderbird
CATEGORIES=		mail

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mozilla.org/projects/thunderbird/
COMMENT=		Redesign of the Mozilla mail client (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 SunOS-5.[89]*-i386

NO_CONFIGURE=		# defined

USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		PLATFORM=${PLATFORM}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

do-build:

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/thunderbird.sh > \
		${WRKDIR}/thunderbird.sh

do-install:
	${INSTALL_DATA_DIR} ${MOZILLA_LIB}
	cd ${WRKSRC} && ${PAX} -rw -pm . ${MOZILLA_LIB}
	${INSTALL_SCRIPT} ${WRKDIR}/thunderbird.sh \
		${PREFIX}/bin/thunderbird-${PLATFORM}

post-install:
# this build wants exactly 'libgtk-1.2.so.0', etc.
.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
	@cd ${MOZILLA_LIB} && \
	${LN} -s ${PREFIX}/lib/libatk-1.0.*so* .;			\
	${LN} -s ${X11PREFIX}/lib/libgdk-x11-2.0.*so* .;		\
	${LN} -s ${PREFIX}/lib/libgdk_pixbuf-2.0.*so* .;		\
	${LN} -s ${PREFIX}/lib/libglib-2.0.*so* .;			\
	${LN} -s ${PREFIX}/lib/libgmodule-2.0.*so* .;			\
	${LN} -s ${PREFIX}/lib/libgobject-2.0.*so* .;			\
	${LN} -s ${X11PREFIX}/lib/libgtk-x11-2.0.*so* .;		\
	${LN} -s ${PREFIX}/lib/libpango-1.0.*so* .;			\
	${LN} -s ${PREFIX}/lib/libpangox-1.0.*so* .;			\
	${LN} -s ${PREFIX}/lib/libpangoxft-1.0.*so* .;			\
	\
	${LN} -s libatk-1.0.so libatk-1.0.so.0;				\
	${LN} -s libgdk-x11-2.0.so libgdk-x11-2.0.so.0;			\
	${LN} -s libgdk_pixbuf-2.0.so libgdk_pixbuf-2.0.so.0;		\
	${LN} -s libglib-2.0.so libglib-2.0.so.0;			\
	${LN} -s libgmodule-2.0.so libgmodule-2.0.so.0;			\
	${LN} -s libgobject-2.0.so libgobject-2.0.so.0;			\
	${LN} -s libgtk-x11-2.0.so libgtk-x11-2.0.so.0;			\
	${LN} -s libpango-1.0.so libpango-1.0.so.0;			\
	${LN} -s libpangox-1.0.so libpangox-1.0.so.0;			\
	${LN} -s libpangoxft-1.0.so libpangoxft-1.0.so.0
.endif
	@${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	@${ECHO} bin/thunderbird-${PLATFORM} >> ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
