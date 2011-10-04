# $NetBSD: builtin.mk,v 1.1 2011/10/04 14:23:17 hans Exp $

BUILTIN_PKG:=	libuuid

BUILTIN_FIND_FILES_VAR=		H_UUID
BUILTIN_FIND_FILES.H_UUID=	/usr/include/uuid/uuid.h
BUILTIN_FIND_GREP.H_UUID=	uuid_generate
BUILTIN_FIND_LIBS:=		uuid

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !empty(BUILTIN_LIB_FOUND.uuid:M[yY][eE][sS]) && \
    empty(H_UUID:M__nonexistent__)

IS_BUILTIN.libuuid=	yes
USE_BUILTIN.libuuid=	yes
BUILTIN_PKG.libuuid=	libuuid-2.18	# whatever, as long as it is big enough

.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-libuuid-pkgconfig

BLKDIR_PKGCFG=		${BUILDLINK_DIR}/lib/pkgconfig
LIBUUID_PKGCFGF=	uuid.pc

override-libuuid-pkgconfig: override-message-libuuid-pkgconfig
override-message-libuuid-pkgconfig:
	@${STEP_MSG} "Magical transformations for libuuid on Solaris."

override-libuuid-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	{						\
	${ECHO} "prefix=/usr";				\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: uuid";				\
	${ECHO} "Description: Universally unique id library";	\
	${ECHO} "Version: ${BUILTIN_VERSION.libuuid}";	\
	${ECHO} "Libs: -Wl,-R\$${libdir} -L\$${libdir} -luuid";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/${LIBUUID_PKGCFGF};
.  endif
.endif
