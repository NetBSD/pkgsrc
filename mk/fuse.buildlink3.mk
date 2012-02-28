# $NetBSD: fuse.buildlink3.mk,v 1.13 2012/02/28 15:05:07 hans Exp $
#
# Makefile fragment for packages using the FUSE framework.
#

# The symbol FUSE_BUILDLINK3_MK is used by filesystems/fuse's bl3.mk,
# so use something else for our include guard.
.if !defined(MK_FUSE_BUILDLINK3_MK)
MK_FUSE_BUILDLINK3_MK=	# defined

.include "bsd.fast.prefs.mk"

.  if ${OPSYS} == "Darwin"

.    if !exists(/usr/local/include/fuse.h)
PKG_FAIL_REASON+=	"Couldn't find fuse headers; please install MacFUSE."
.    endif

do-configure-pre-hook: override-fuse-pkgconfig

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Setting up usage of native MacFUSE."

override-fuse-pkgconfig:
	${RUN}						\
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;	\
	${LN} -s /usr/local/lib/pkgconfig/fuse.pc	\
	    ${BUILDLINK_DIR}/lib/pkgconfig/fuse.pc

BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/fuse

.  elif ${OPSYS} == "Linux"

.    include "../../filesystems/fuse/buildlink3.mk"

.  elif !empty(MACHINE_PLATFORM:MSunOS-5.11-*)

.    if !exists(/usr/include/fuse/fuse.h)
PKG_FAIL_REASON+=	"Couldn't find fuse headers, please install libfuse."
.    endif
.    include "../../filesystems/fuse/buildlink3.mk"

.  elif ${OPSYS} == "NetBSD"
.     if !exists(/usr/include/fuse.h)
PKG_FAIL_REASON+=	"Couldn't find fuse headers, please install librefuse."
.     endif

.    if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-fuse-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig
FUSE_PKGCFGF=	fuse.pc

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Magical transformations for fuse on NetBSD."

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
