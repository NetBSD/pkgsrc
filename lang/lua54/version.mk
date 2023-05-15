# $NetBSD: version.mk,v 1.6 2023/05/15 08:17:11 nikita Exp $

LUA_VERSION=	5.4.6

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
