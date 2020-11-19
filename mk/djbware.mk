# $NetBSD: djbware.mk,v 1.31 2020/11/19 08:11:18 schmonz Exp $
#
# Makefile fragment for packages with djb-style build machinery
#
# Common functions provided:
# * a boilerplate RESTRICTED clause
# * typical defaults for BUILD_TARGET and INSTALL_TARGET
# * typical values for conf-* files
# * replace inline definitions of errno with "#include <errno.h>"
#

.if !defined(DJBWARE_MK)
DJBWARE_MK=		# defined

DJB_MAKE_TARGETS?=	YES
DJB_BUILD_TARGETS?=	# empty
DJB_INSTALL_TARGETS?=	# empty
DJB_SLASHPACKAGE?=	NO
.if !empty(DJB_SLASHPACKAGE:M[yY][eE][sS])
DJB_CONFIG_DIR?=	${WRKSRC}/src
DJB_BUILD_ARGS?=	# empty
.else
DJB_CONFIG_DIR?=	${WRKSRC}
.endif
DJB_CONFIG_PREFIX?=	${PREFIX}
DJB_CONFIG_HOME?=	conf-home
DJB_CONFIG_CMDS?=	${DO_NADA}

.if ${LICENSE} == "djb-nonlicense"
# So-licensed packages that install totally unmodified may want to opt out
RESTRICTED?=		modified source and binaries may not be distributed
NO_BIN_ON_CDROM?=	${RESTRICTED}
NO_BIN_ON_FTP?=		${RESTRICTED}
.endif

.if !empty(DJB_MAKE_TARGETS:M[yY][eE][sS])
BUILD_TARGET?=		it ${DJB_BUILD_TARGETS}
INSTALL_TARGET?=	setup check ${DJB_INSTALL_TARGETS}
.endif

.if !defined(NO_CONFIGURE) && !target(do-configure)
do-configure:
	${RUN}cd ${DJB_CONFIG_DIR};		\
	for i in conf-*; do ${CP} $${i} $${i}.orig_dist; done;		\
	${ECHO} ${DESTDIR:Q}${DJB_CONFIG_PREFIX:Q} > conf-destdir;	\
	[ -f ${DJB_CONFIG_HOME} ] && \
		${ECHO} ${DJB_CONFIG_PREFIX} > ${DJB_CONFIG_HOME};	\
	[ -f conf-cc ] && \
		${ECHO} ${CC:Q} ${CFLAGS:Q} ${CPPFLAGS:Q} > conf-cc;	\
	[ -f conf-ld ] && \
		${ECHO} ${CC:Q} ${_STRIPFLAG_CC} ${LDFLAGS:Q} > conf-ld;\
	[ -f conf-bin ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/bin > conf-bin;		\
	[ -f conf-man ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/${PKGMANDIR} > conf-man;	\
	[ -f conf-qmail ] && \
		${ECHO} ${QMAILDIR} > conf-qmail;			\
	[ -f conf-bgincs ] && \
		${ECHO} ${PREFIX}/include > conf-bgincs;		\
	[ -f conf-bglibs ] && \
		${ECHO} ${PREFIX}/lib > conf-bglibs;			\
	${DJB_CONFIG_CMDS}
.endif

.if !target(do-build) && !empty(DJB_SLASHPACKAGE:M[yY][eE][sS])
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} package/compile ${DJB_BUILD_ARGS}
.endif

# Set SUBST_CLASSES+=djberrno for packages that need this fix
SUBST_STAGE.djberrno=	do-configure
SUBST_FILES.djberrno?=	error.h
SUBST_SED.djberrno=	-e 's|^extern\ int\ errno\;|\#include \<errno.h\>|'
SUBST_MESSAGE.djberrno=	Correcting definition of errno.

.endif	# DJBWARE_MK
