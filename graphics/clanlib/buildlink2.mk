# $NetBSD: buildlink2.mk,v 1.6 2003/05/02 11:55:12 wiz Exp $

.if !defined(CLANLIB_BUILDLINK2_MK)
CLANLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ClanLib
BUILDLINK_DEPENDS.ClanLib?=	ClanLib>=0.4.4nb4
BUILDLINK_PKGSRCDIR.ClanLib?=	../../graphics/clanlib

EVAL_PREFIX+=			BUILDLINK_PREFIX.ClanLib=ClanLib
BUILDLINK_PREFIX.ClanLib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.ClanLib=	lib/libclanCore.*
BUILDLINK_FILES.ClanLib+=	lib/ClanLib/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/*.h
BUILDLINK_FILES.ClanLib+=	include/ClanLib/Core/*/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/GL/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/GUI/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/Lua/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/MIDI/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/MPEG/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/Magick/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/MikMod/*
BUILDLINK_FILES.ClanLib+=	include/ClanLib/png/*

.include "../../mk/pthread.buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	ClanLib-buildlink

ClanLib-buildlink: _BUILDLINK_USE

.endif	# CLANLIB_BUILDLINK2_MK
