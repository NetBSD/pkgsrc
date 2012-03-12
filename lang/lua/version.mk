# $NetBSD: version.mk,v 1.2 2012/03/12 15:49:27 wiz Exp $

LUA_VERSION=	5.1.5

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
