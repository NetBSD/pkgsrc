# $NetBSD: buildlink3.mk,v 1.2 2025/02/09 13:34:24 wiz Exp $

BUILDLINK_TREE+=	alire

.if !defined(ALIRE_BUILDLINK3_MK)
ALIRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alire+=	alire>=2.0.0rc1
BUILDLINK_PKGSRCDIR.alire=	../../devel/alire
BUILDLINK_DEPMETHOD.alire?=	build

BUILDLINK_AUTO_VARS.alire=	no
BUILDLINK_AUTO_DIRS.alire=	no

BUILDLINK_FILES.alire=			bin/alr share/gpr/manifests/alr*
BUILDLINK_CONTENTS_FILTER.alire=	\
	${EGREP} '(bin/alr|share/gpr/manifests/alr.*)'

.endif

BUILDLINK_TREE+=	-alire
