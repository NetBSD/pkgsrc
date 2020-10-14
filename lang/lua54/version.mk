# $NetBSD: version.mk,v 1.2 2020/10/14 16:42:59 wiz Exp $

LUA_VERSION=	5.4.1

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
