# $NetBSD: version.mk,v 1.2 2014/01/02 19:57:39 wiz Exp $

LUA_VERSION=	5.2.3

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
