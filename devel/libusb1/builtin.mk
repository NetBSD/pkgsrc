# $NetBSD: builtin.mk,v 1.2 2015/02/04 23:44:34 tnn Exp $

BUILTIN_PKG:=	libusb1

BUILTIN_FIND_HEADERS_VAR:=	H_LIBUSB
BUILTIN_FIND_HEADERS.H_LIBUSB=	libusb.h

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(IS_BUILTIN.libusb1)
IS_BUILTIN.libusb1=		no
.  if empty(H_LIBUSB:M__nonexistent__)
IS_BUILTIN.libusb1=		yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libusb1

.if !defined(USE_BUILTIN.libusb1)
USE_BUILTIN.libusb1=	${IS_BUILTIN.libusb1}
.endif

.if !empty(USE_BUILTIN.libusb1:M[yY][eE][sS])
.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-libusb-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig
LIBUSB_PKGCFGF=	libusb-1.0.pc

override-libusb-pkgconfig: override-message-libusb-pkgconfig
override-message-libusb-pkgconfig:
	@${STEP_MSG} "Generating pkg-config file for builtin libusb1 package."

override-libusb-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	{						\
	${ECHO} "prefix=${LIBUSB_PREFIX}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: libusb-1.0";				\
	${ECHO} "Description: library for USB access";	\
	${ECHO} "Version: ${BUILTIN_VERSION.libusb1}";	\
	${ECHO} "Libs: -Wl,-R\$${libdir} -L\$${libdir} -lusb";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/${LIBUSB_PKGCFGF};
.  endif
.endif
