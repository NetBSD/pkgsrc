# $NetBSD: builtin.mk,v 1.6 2024/02/10 16:40:56 wiz Exp $

BUILTIN_PKG:=	libusb1

BUILTIN_FIND_PKGCONFIG_FILES_VAR:=		PC_LIBUSB1
BUILTIN_FIND_PKGCONFIG_FILES.PC_LIBUSB1=	libusb-1.0.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(IS_BUILTIN.libusb1)
IS_BUILTIN.libusb1=	no
.  if empty(PC_LIBUSB1:M__nonexistent__)
IS_BUILTIN.libusb1=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libusb1

.if !defined(USE_BUILTIN.libusb1)
USE_BUILTIN.libusb1=	${IS_BUILTIN.libusb1}
.endif

.if ${USE_BUILTIN.libusb1:tl} == yes
.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
.PHONY: do-configure-pre-hook
do-configure-pre-hook: link-libusb-pkgconfig

BLKDIR_PKGCFG=		${BUILDLINK_DIR}/lib/pkgconfig
LIBUSB1_PKGCFGF=	${BUILTIN_FIND_PKGCONFIG_FILES.PC_LIBUSB1}

.PHONY: link-libusb-pkgconfig link-message-libusb-pkgconfig
link-libusb-pkgconfig: link-message-libusb-pkgconfig
link-message-libusb-pkgconfig:
	@${STEP_MSG} "Linking ${PC_LIBUSB1} file into ${BUILDLINK_DIR}."

link-libusb-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	${LN} -sf ${PC_LIBUSB1} ${BLKDIR_PKGCFG}/${LIBUSB1_PKGCFGF}
.  endif
.endif
