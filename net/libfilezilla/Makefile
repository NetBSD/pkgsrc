# $NetBSD: Makefile,v 1.2 2016/07/19 18:42:22 wiz Exp $

DISTNAME=	libfilezilla-0.5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filezilla/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.filezilla-project.org/
COMMENT=	Library for building high-performing, platform-independent programs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

.include "../../mk/bsd.pkg.mk"
