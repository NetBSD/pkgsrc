# $NetBSD: deforaos-configure.mk,v 1.8 2022/07/11 01:38:20 khorben Exp $
#
# used by audio/deforaos-mixer/Makefile
# used by devel/deforaos-asm/Makefile
# used by devel/deforaos-coder/Makefile
# used by devel/deforaos-cpp/Makefile
# used by sysutils/deforaos-browser/Makefile
# used by x11/deforaos-libdesktop/Makefile
# used by x11/deforaos-locker/Makefile
# used by x11/deforaos-panel/Makefile

BUILD_DEPENDS+=	deforaos-configure-[0-9]*:../../devel/deforaos-configure

DEFORAOS_CONFIGURE?=		${PREFIX}/bin/configure
DEFORAOS_CONFIGURE_ARGS?=	-v
DEFORAOS_CONFIGURE_DIRS?=	.
DEFORAOS_CONFIGURE_MODE?=
_BUILD_DEFS+=			DEFORAOS_CONFIGURE \
				DEFORAOS_CONFIGURE_ARGS \
				DEFORAOS_CONFIGURE_DIRS \
				DEFORAOS_CONFIGURE_MODE
_DO_CONFIGURE_TARGETS+=		do-configure-deforaos

do-configure-deforaos:
.if !empty(DEFORAOS_CONFIGURE_MODE)
	@${ECHO_MSG} "Running DeforaOS configure (${DEFORAOS_CONFIGURE_MODE})"
	@${RUN} cd ${WRKSRC} && ${DEFORAOS_CONFIGURE} \
		-M ${DEFORAOS_CONFIGURE_MODE} \
		${DEFORAOS_CONFIGURE_ARGS} \
		${DEFORAOS_CONFIGURE_DIRS}
.else
	@${ECHO_MSG} "Running DeforaOS configure"
	@${RUN} cd ${WRKSRC} && ${DEFORAOS_CONFIGURE} \
		${DEFORAOS_CONFIGURE_ARGS} \
		${DEFORAOS_CONFIGURE_DIRS}
.endif
