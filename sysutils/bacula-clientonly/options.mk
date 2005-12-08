# $NetBSD: options.mk,v 1.1 2005/12/08 01:04:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bacula
PKG_SUPPORTED_OPTIONS=	gnome-console wx-console tray-monitor

.include "../../mk/bsd.options.mk"
