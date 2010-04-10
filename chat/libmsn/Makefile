# $NetBSD: Makefile,v 1.3 2010/04/10 00:11:49 markd Exp $

DISTNAME=	libmsn-4.1
CATEGORIES=	chat
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=libmsn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libmsn
COMMENT=	library for connecting to Microsoft's MSN Messenger service
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES+= c c++

PKGCONFIG_OVERRIDE+=	libmsn.pc.cmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
