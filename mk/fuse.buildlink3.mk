# $NetBSD: fuse.buildlink3.mk,v 1.19 2016/01/28 20:50:07 tron Exp $
#
# Makefile fragment for packages using the FUSE framework.
#

# The symbol FUSE_BUILDLINK3_MK is used by filesystems/fuse's bl3.mk,
# so use something else for our include guard.
.if !defined(MK_FUSE_BUILDLINK3_MK)
MK_FUSE_BUILDLINK3_MK=	# defined

.include "bsd.fast.prefs.mk"

.  if ${OPSYS} == "Darwin"

# On Darwin, we only attempt to support "Fuse for OS X", known as
# "OSXFUSE".  MacFuse is dead, and fuse4x is merging into OSXFUSE.

.    if !exists(/usr/local/lib/pkgconfig/osxfuse.pc)
PKG_FAIL_REASON+=	\
	"Couldn't find fuse; please install OSXFUSE."
.    endif

do-configure-pre-hook: override-fuse-pkgconfig

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Setting up usage of native fuse."

override-fuse-pkgconfig:
	${RUN}						\
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;	\
	${LN} -s /usr/local/lib/pkgconfig/osxfuse.pc	\
	    ${BUILDLINK_DIR}/lib/pkgconfig/fuse.pc

BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/osxfuse
# Too much!  But allows -losxfuse to work.
BUILDLINK_PASSTHRU_DIRS+=	/usr/local/lib

.  elif ${OPSYS} == "Linux"

.    include "../../filesystems/fuse/buildlink3.mk"

.  elif !empty(MACHINE_PLATFORM:MSunOS-5.11-*)

.    if !exists(/usr/include/fuse/fuse.h)
PKG_FAIL_REASON+=	"Couldn't find fuse headers, please install libfuse."
.    endif
.    include "../../filesystems/fuse/buildlink3.mk"

.  elif ${OPSYS} == "NetBSD" || ${OPSYS} == "Minix" || \
        !empty(MACHINE_PLATFORM:MDragonFly-[3-9]*-*)
.     if !exists(/usr/include/fuse.h)
PKG_FAIL_REASON+=	"Couldn't find fuse headers, please install librefuse."
.     endif

CFLAGS.NetBSD+=		-D_KERNTYPES
LDFLAGS.DragonFly+=	-lpuffs

.    if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-fuse-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig
FUSE_PKGCFGF=	fuse.pc

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Generating pkg-config file for builtin fuse package."

override-fuse-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	{						\
	${ECHO} "prefix=/usr";				\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO}	"";					\
	${ECHO} "Name: FuSE";				\
	${ECHO} "Description: Filesystem USEr Space";	\
	${ECHO} "Version: 2.6.0";			\
	${ECHO} "Libs: -Wl,-R\$${libdir} -L\$${libdir} -lrefuse";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/${FUSE_PKGCFGF};

.    endif # pkg-config

# To make sure
BUILDLINK_TRANSFORM+=	l:fuse:refuse

# Undefined reference to fuse_main()... use fuse_exit() for now.
.    if defined(GNU_CONFIGURE)
SUBST_CLASSES+=		refuse
SUBST_STAGE.refuse=	pre-configure
SUBST_FILES.refuse=	configure configure.ac configure.in
SUBST_SED.refuse=	-e "s|fuse_main|fuse_exit|g"
.    endif

.  else # !NetBSD

PKG_FAIL_REASON+=	"Your OS is not supported by the FUSE pkgsrc framework."

.  endif # end of Operating Systems

.endif # MK_FUSE_BUILDLINK3_MK
