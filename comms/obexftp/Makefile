# $NetBSD: Makefile,v 1.23 2023/06/06 12:40:24 riastradh Exp $
#

DISTNAME=	obexftp-0.24-Source
PKGNAME=	obexftp-0.24
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://gitorious.org/obexftp
COMMENT=	File copying over the Object Exchange (OBEX) protocol
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	cmake pkg-config

CMAKE_ARGS+=	-DENABLE_PERL:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_PYTHON:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_RUBY:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_TCL:BOOL=OFF

TOOL_DEPENDS+=	asciidoc>=8.6.6:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto>=0.0.25:../../textproc/xmlto

BUILD_TARGET=	all doc

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
