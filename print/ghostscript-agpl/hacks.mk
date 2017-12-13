# $NetBSD: hacks.mk,v 1.2 2017/12/13 13:02:06 gdt Exp $

### [Tue Jan  9 15:57:05 EST 2007 : tv]
### Interix has u_int64_t, but not uint64_t
### (gdevpdfe.c doesn't use the autoconf test based int64 type,
### but absolutely requires a 64-bit unsigned int)
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		interix-uint64_t
CPPFLAGS.Interix+=	-Duint64_t=u_int64_t
.endif

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
