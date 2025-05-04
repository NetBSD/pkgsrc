# $NetBSD: builtin.mk,v 1.2 2025/05/04 07:18:03 vins Exp $

BUILTIN_PKG:=	libudev

BUILTIN_FIND_PKGCONFIG_FILES_VAR:=		LIBUDEV_PC
BUILTIN_FIND_PKGCONFIG_FILES.LIBUDEV_PC=	libudev.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(IS_BUILTIN.libudev)
IS_BUILTIN.libudev=	no
.  if empty(LIBUDEV_PC:M__nonexistent__)
IS_BUILTIN.libudev=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libudev

.if !defined(USE_BUILTIN.libudev)
USE_BUILTIN.libudev=	${IS_BUILTIN.libudev}
.endif

.PHONY: link-libudev-pkgconfig link-message-libudev-pkgconfig \
	do-configure-pre-hook

.if ${USE_BUILTIN.libudev:tl} == yes
.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: link-libudev-pkgconfig

BLKDIR_PKGCFG=		${BUILDLINK_DIR}/lib/pkgconfig
LIBUDEV_PKGCFGF=	${BUILTIN_FIND_PKGCONFIG_FILES.LIBUDEV_PC}

link-libudev-pkgconfig: link-message-libudev-pkgconfig
link-message-libudev-pkgconfig:
	@${STEP_MSG} "Linking ${LIBUDEV_PC} file into ${BUILDLINK_DIR}."

link-libudev-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	${LN} -sf ${LIBUDEV_PC} ${BLKDIR_PKGCFG}/${LIBUDEV_PKGCFGF}
.  endif
.endif
