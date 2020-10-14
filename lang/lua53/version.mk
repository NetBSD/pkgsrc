# $NetBSD: version.mk,v 1.7 2020/10/14 16:39:50 wiz Exp $

LUA_VERSION=	5.3.6

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
