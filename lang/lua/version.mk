# $NetBSD: version.mk,v 1.1 2009/01/11 23:15:55 minskim Exp $

LUA_VERSION=	5.1.4

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
