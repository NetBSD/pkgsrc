# $NetBSD: mk-c.mk,v 1.4 2014/07/13 15:52:36 cheusov Exp $

TOOL_DEPENDS+=	${BUILDLINK_API_DEPENDS.mk-c}:${BUILDLINK_PKGSRCDIR.mk-c}

MAKE_PROGRAM=	mkcmake
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} INSTALL=${INSTALL:Q}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

do-configure:
	set -e; cd ${WRKSRC}; \
	env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} errorcheck

###
BUILDLINK_TREE+=	mk-c

.if !defined(MK_CONFIGURE_BUILDLINK3_MK)
MK_CONFIGURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mk-c+=	mk-configure>=0.27.0
BUILDLINK_PKGSRCDIR.mk-c=	../../devel/mk-configure
BUILDLINK_DEPMETHOD.mk-c=	build
BUILDLINK_INCDIRS.mk-c=		include share/mk-configure/features
.endif # MK_CONFIGURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mk-c
