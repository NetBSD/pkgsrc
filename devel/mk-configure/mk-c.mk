# $NetBSD: mk-c.mk,v 1.11 2021/03/24 21:58:42 cheusov Exp $

TOOL_DEPENDS+=	${BUILDLINK_API_DEPENDS.mk-c}:${BUILDLINK_PKGSRCDIR.mk-c}

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=		MKCOMPILERSETTINGS=yes
CONFIGURE_TARGET?=	configure

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
