# $NetBSD: hacks.mk,v 1.5 2025/04/21 21:14:14 wiz Exp $

### [ Thu Nov 13 12:30:45 EST 2008 : chuck]
### gs has hand-rolled shared lib handling that doesn't do the right
### thing on Darwin by default, you need to reconfigure unix-dll.mak
### to make it work.
.if ${OPSYS} == "Darwin"
post-patch:
	${SED} -e 's/^#Darwin#//' ${WRKSRC}/base/unix-dll.mak > \
		${WRKSRC}/base/unix-darwin.mak
	${MV} ${WRKSRC}/base/unix-darwin.mak ${WRKSRC}/base/unix-dll.mak
.endif

## Copied from ../../fonts/fontforge/hacks.mk.  See
## https://gnats.netbsd.org/50902

# On NetBSD 7.x for a while a version of freetype2 that was supposed
# to have ftttdrv.h was shipped without actually installing that
# header.

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native" && ${MACHINE_PLATFORM:MNetBSD-7.*} && \
	!exists(/usr/X11R7/include/freetype2/ftttdrv.h)
BUILDLINK_TARGETS+=	buildlink-freetype2-ftttdrv.h
.PHONY: buildlink-freetype2-ftttdrv.h
buildlink-freetype2-ftttdrv.h:
	${RUN}								\
	dest=${BUILDLINK_DIR}"/include/freetype2/ftttdrv.h";		\
	${ECHO_BUILDLINK_MSG} "Hacking around missing ftttdrv.h";	\
	${ECHO} '#define TT_INTERPRETER_VERSION_35  35' >> "$$dest";	\
	${ECHO} '#define TT_INTERPRETER_VERSION_38  38' >> "$$dest"
.endif
