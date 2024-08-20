# $NetBSD: options.mk,v 1.13 2024/08/20 16:34:32 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uhd
PKG_SUPPORTED_OPTIONS=	doxygen

.include "../../mk/bsd.options.mk"

PLIST_SRC=	${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=	doxygen>=1.8.15:../../devel/doxygen
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MANUAL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOXYGEN=ON
# different versions of Doxygen generate different files
PLIST_SRC+=	${WRKDIR}/PLIST.DOCS
.PHONY: doxygen-plist
post-install: doxygen-plist
doxygen-plist:
	${RM} -f ${WRKDIR}/PLIST.DOCS
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/uhd/doxygen -type f -print > ${WRKDIR}/PLIST.DOCS
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MANUAL=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOXYGEN=OFF
.endif
