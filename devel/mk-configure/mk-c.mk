# $NetBSD: mk-c.mk,v 1.12 2025/03/26 20:26:26 rillig Exp $

TOOL_DEPENDS+=	${BUILDLINK_API_DEPENDS.mk-c}:${BUILDLINK_PKGSRCDIR.mk-c}

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=		MKCOMPILERSETTINGS=yes
CONFIGURE_TARGET?=	configure

# Fix the build on NetBSD 9 since it passes .MAKE.LEVEL.ENV via MAKEFLAGS,
# and the pkgsrc make doesn't allow this variable.
MAKE_ENV+=		MAKEFLAGS=

.if !target(do-configure)
do-configure:
	set -e; cd ${WRKSRC}; \
	env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${CONFIGURE_TARGET}
.endif

###
BUILDLINK_TREE+=	mk-c

.if !defined(MK_CONFIGURE_BUILDLINK3_MK)
MK_CONFIGURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mk-c+=	mk-configure>=0.28.0
BUILDLINK_PKGSRCDIR.mk-c=	../../devel/mk-configure
BUILDLINK_DEPMETHOD.mk-c=	build
BUILDLINK_INCDIRS.mk-c=		include share/mk-configure/features
.endif # MK_CONFIGURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mk-c
