# $NetBSD: buildlink3.mk,v 1.4 2026/02/06 10:05:13 wiz Exp $

BUILDLINK_TREE+=	mimetreeparser

.if !defined(MIMETREEPARSER_BUILDLINK3_MK)
MIMETREEPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mimetreeparser+=	mimetreeparser>=25.08.3
BUILDLINK_ABI_DEPENDS.mimetreeparser?=	mimetreeparser>=25.08.3nb3
BUILDLINK_PKGSRCDIR.mimetreeparser?=	../../mail/mimetreeparser

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MIMETREEPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mimetreeparser
