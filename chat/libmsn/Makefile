# $NetBSD: Makefile,v 1.14 2023/10/24 22:08:21 wiz Exp $

DISTNAME=	libmsn-4.2.1
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmsn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libmsn
COMMENT=	Library for connecting to Microsoft's MSN Messenger service
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03

PKGCONFIG_OVERRIDE+=	libmsn.pc.cmake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
