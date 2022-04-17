# $NetBSD: deforaos-configure.mk,v 1.4 2022/04/17 02:55:32 khorben Exp $
#
# used by audio/deforaos-mixer/Makefile
# used by devel/deforaos-asm/Makefile
# used by devel/deforaos-cpp/Makefile
# used by x11/deforaos-libdesktop/Makefile

BUILD_DEPENDS+=	deforaos-configure-[0-9]*:../../devel/deforaos-configure

DEFORAOS_CONFIGURE?=		${PREFIX}/bin/configure
DEFORAOS_CONFIGURE_ARGS?=	-v
DEFORAOS_CONFIGURE_DIRS?=	.
_BUILD_DEFS+=			DEFORAOS_CONFIGURE DEFORAOS_CONFIGURE_ARGS DEFORAOS_CONFIGURE_DIRS
_DO_CONFIGURE_TARGETS+=		do-configure-deforaos

do-configure-deforaos:
.for dir in ${DEFORAOS_CONFIGURE_DIRS}
	@${ECHO_MSG} "Running DeforaOS configure in ${dir}"
	@${RUN} cd ${WRKSRC} && ${DEFORAOS_CONFIGURE} ${DEFORAOS_CONFIGURE_ARGS} ${dir}
.endfor
