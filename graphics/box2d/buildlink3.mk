# $NetBSD: buildlink3.mk,v 1.2 2026/09/22 07:55:31 ryoon Exp $

BUILDLINK_TREE+=	box2d

.if !defined(BOX2D_BUILDLINK3_MK)
BOX2D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.box2d+=	box2d>=3.1.1
BUILDLINK_PKGSRCDIR.box2d?=	../../graphics/box2d

BUILDLINK_TARGETS+=	box2d-fake-pc

.PHONY: box2d-fake-pc
box2d-fake-pc:
	${RUN} \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	{ ${ECHO} "Name: box2d"; \
	${ECHO} "Description: 2D physics engine for games"; \
	${ECHO} "Version: 3.1.1"; \
	${ECHO} "Cflags: -I${BUILDLINK_PREFIX.box2d}/include"; \
	${ECHO} "Libs: -L${BUILDLINK_PREFIX.box2d}/lib" \
	"${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.box2d}/lib" \
	"-lbox2d"; \
	} > ${BUILDLINK_DIR}/lib/pkgconfig/box2d.pc; \

.endif	# BOX2D_BUILDLINK3_MK

BUILDLINK_TREE+=	-box2d
