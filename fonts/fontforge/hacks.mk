# $NetBSD: hacks.mk,v 1.2 2017/05/04 19:23:18 adam Exp $

# On NetBSD 7.x for a while a version of freetype2 that was supposed
# to have ftttdrv.h was shipped without actually installing that
# header. This causes fontforge-20150824 and up to fail to build.

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native" && !empty(MACHINE_PLATFORM:MNetBSD-7.*) && \
	!exists(/usr/X11R7/include/freetype2/ftttdrv.h)
BUILDLINK_TARGETS+=	buildlink-freetype2-ftttdrv.h
buildlink-freetype2-ftttdrv.h:
	${RUN}								\
	dest=${BUILDLINK_DIR}"/include/freetype2/ftttdrv.h";		\
	${ECHO_BUILDLINK_MSG} "Hacking around missing ftttdrv.h";	\
	${ECHO} '#define TT_INTERPRETER_VERSION_35  35' >> "$$dest";	\
	${ECHO} '#define TT_INTERPRETER_VERSION_38  38' >> "$$dest"
.endif
