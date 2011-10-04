# $NetBSD: builtin.mk,v 1.3 2011/10/04 14:19:47 hans Exp $

BUILTIN_PKG:=	libusb
PKGCONFIG_BASE.libusb=	/usr
PKGCONFIG_FILE.libusb=	/usr/bin/libusb-config /usr/sfw/bin/libusb-config
BUILTIN_VERSION_SCRIPT.libusb=	${FIND_FILES_libusb} --version \#
.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if !empty(USE_BUILTIN.libusb:M[yY][eE][sS])
LIBUSB_PREFIX=			${FIND_FILES_libusb:S/\/bin\/libusb-config//}
BUILDLINK_FILES.libusb=		bin/libusb-config
BUILDLINK_PASSTHRU_DIRS+=	${LIBUSB_PREFIX}/lib ${LIBUSB_PREFIX}/include

.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-libusb-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig
LIBUSB_PKGCFGF=	libusb.pc

override-libusb-pkgconfig: override-message-libusb-pkgconfig
override-message-libusb-pkgconfig:
	@${STEP_MSG} "Magical transformations for libusb on Solaris."

override-libusb-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	{						\
	${ECHO} "prefix=${LIBUSB_PREFIX}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: libusb";				\
	${ECHO} "Description: library for USB access";	\
	${ECHO} "Version: ${BUILTIN_VERSION.libusb}";	\
	${ECHO} "Libs: -Wl,-R\$${libdir} -L\$${libdir} -lusb";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/${LIBUSB_PKGCFGF};
.  endif
.endif
