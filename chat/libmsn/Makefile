# $NetBSD: Makefile,v 1.9 2016/03/05 11:27:41 jperkin Exp $

DISTNAME=	libmsn-4.2.1
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmsn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libmsn
COMMENT=	Library for connecting to Microsoft's MSN Messenger service
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES= c c++

PKGCONFIG_OVERRIDE+=	libmsn.pc.cmake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
