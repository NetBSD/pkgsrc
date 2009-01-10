# $NetBSD: Makefile,v 1.1.1.1 2009/01/10 08:56:39 markd Exp $

DISTNAME=	libmsn-4.0-beta2
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	chat
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=libmsn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libmsn
COMMENT=	library for connecting to Microsoft's MSN Messenger service

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES+= c c++

PKGCONFIG_OVERRIDE+=	libmsn.pc.cmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
