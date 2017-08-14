# $NetBSD: Makefile,v 1.10 2017/08/14 21:19:23 wiz Exp $

DISTNAME=	libfilezilla-0.10.1
CATEGORIES=	devel
MASTER_SITES=	http://download.filezilla-project.org/libfilezilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.filezilla-project.org/
COMMENT=	Library for building high-performing, platform-independent programs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

# GCC 4.9 is required to support C++14
GCC_REQD+=	4.9

.include "../../mk/bsd.pkg.mk"
