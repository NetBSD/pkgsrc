# $NetBSD: version.mk,v 1.7 2024/06/28 05:35:11 wiz Exp $

LUA_VERSION=	5.4.7

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
