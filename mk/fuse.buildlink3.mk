# $NetBSD: fuse.buildlink3.mk,v 1.24 2022/01/22 18:23:43 pho Exp $
#
# Makefile fragment for packages using the FUSE framework.
#

# The symbol FUSE_BUILDLINK3_MK is used by filesystems/fuse's bl3.mk,
# so use something else for our include guard.
.if !defined(MK_FUSE_BUILDLINK3_MK)
MK_FUSE_BUILDLINK3_MK=	# defined

.include "bsd.fast.prefs.mk"

.  if ${OPSYS} == "Darwin"

# On Darwin, we only attempt to support macFUSE.
# https://macfuse.io/

.    if !exists(/usr/local/lib/pkgconfig/osxfuse.pc) && \
	!exists(/usr/local/lib/pkgconfig/fuse.pc)
PKG_FAIL_REASON+=	\
	"Couldn't find fuse; please install macFUSE."
.    endif

do-configure-pre-hook: override-fuse-pkgconfig

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Setting up usage of native fuse."

override-fuse-pkgconfig:
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
.if exists(/usr/local/lib/pkgconfig/osxfuse.pc)
	${LN} -s /usr/local/lib/pkgconfig/osxfuse.pc	\
	    ${BUILDLINK_DIR}/lib/pkgconfig/fuse.pc
.elif exists(/usr/local/lib/pkgconfig/fuse.pc)
	${LN} -s /usr/local/lib/pkgconfig/fuse.pc	\
	    ${BUILDLINK_DIR}/lib/pkgconfig/fuse.pc
.endif

BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/osxfuse
BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/fuse
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
H_FUSE=			/usr/include/fuse.h
.      if !exists(${H_FUSE})
PKG_FAIL_REASON+=	"Couldn't find fuse headers, please install librefuse."
.      endif

# XXX: -D_KERNTYPES can be removed when NetBSD 9 reaches its EOL.
CFLAGS.NetBSD+=		-D_KERNTYPES -D_NETBSD_SOURCE
LDFLAGS.DragonFly+=	-lpuffs

.    if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-fuse-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig

override-fuse-pkgconfig: override-message-fuse-pkgconfig
override-message-fuse-pkgconfig:
	@${STEP_MSG} "Generating pkg-config file for builtin fuse package."

BUILTIN_VERSION.fuse!=					\
	${AWK} '/\#[ \t]+define/ { sub("\#[ \t]+define", "\#define", $$0); } \
		/\#define[ \t]+_REFUSE_MAJOR_VERSION_[ \t]/ { major = $$3; } \
		/\#define[ \t]+_REFUSE_MINOR_VERSION_[ \t]/ { minor = $$3; } \
		/\#define[ \t]+FUSE_MAJOR_VERSION[ \t]/ { if (major == "") major = $$3; } \
		/\#define[ \t]+FUSE_MINOR_VERSION[ \t]/ { if (minor == "") minor = $$3; } \
		END { \
			if (major != "" && minor != "") \
				print major "." minor; \
			else \
				print ""; \
		}' ${H_FUSE}

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
	${ECHO} "Version: ${BUILTIN_VERSION.fuse}";			\
	${ECHO} "Libs: -Wl,-R\$${libdir} -L\$${libdir} -lrefuse";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/fuse.pc;			\
	if ${PKG_ADMIN} pmatch 'fuse>=3' 'fuse-${BUILTIN_VERSION.fuse}'; then	\
		${LN} ${BLKDIR_PKGCFG}/fuse.pc ${BLKDIR_PKGCFG}/fuse3.pc;	\
	fi

.    endif # pkg-config

# To make sure
BUILDLINK_TRANSFORM+=	l:fuse:refuse

# Undefined reference to fuse_main()... use fuse_exit() for now.
.    if defined(GNU_CONFIGURE)
SUBST_CLASSES+=		refuse
SUBST_STAGE.refuse=	pre-configure
SUBST_FILES.refuse=	configure configure.ac configure.in
SUBST_SED.refuse=	-e "s|fuse_main|fuse_exit|g"
SUBST_NOOP_OK.refuse=	yes # only some packages need this hack
.    endif

.  else # !NetBSD

PKG_FAIL_REASON+=	"Your OS is not supported by the FUSE pkgsrc framework."

.  endif # end of Operating Systems

.endif # MK_FUSE_BUILDLINK3_MK
