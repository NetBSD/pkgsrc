# $NetBSD: Makefile,v 1.13 2023/05/06 19:08:56 ryoon Exp $

DISTNAME=	alure-1.2
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	bastiangermann@fishpost.de
HOMEPAGE=	https://kcat.strangesoft.net/alure
COMMENT=	Helps manage common tasks with OpenAL applications
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF -DDUMB=OFF -DDYNLOAD=OFF

PKGCONFIG_OVERRIDE+=	alure-static.pc.in
PKGCONFIG_OVERRIDE+=	alure.pc.in

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	alincldir openalincldir

.if ${OPSYS} == "Darwin"
PLIST.openalincldir=	yes
.else
PLIST.alincldir=	yes
.endif

.include "options.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
