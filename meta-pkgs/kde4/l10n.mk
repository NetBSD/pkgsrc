# $NetBSD: l10n.mk,v 1.1.1.1 2009/10/02 21:43:12 markd Exp $

# This file provides useful defaults for the l10n packages of koffice.
#
# The following variables shall be defined when using this file.
#
# KDE_LANGCODE
#       The language code (e.g. de, pt_BR)
#
# KDE_LANGUAGE
#       The full name of the language (e.g. German, Brasilian)
#


DISTNAME=	kde-l10n-${KDE_LANGCODE}-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/kde-/kde4-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE_I18N}

COMMENT=	${KOFFICE_LANGUAGE} language pack for KDE4

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt

BUILDLINK_DEPMETHOD.qt4-libs=	build
BUILDLINK_DEPMETHOD.qt4-qdbus=	build
BUILDLINK_DEPMETHOD.kdelibs=	build

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
