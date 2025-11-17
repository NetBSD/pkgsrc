# $NetBSD: Makefile,v 1.11 2025/11/17 11:00:36 wiz Exp $

DISTNAME=	libfirm-1.21.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libfirm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libfirm.sourceforge.net/
COMMENT=	Provides a graph-based SSA representation of programs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libfirm.pc.in

#
# NOTE: jvm support requires dlopen/dlsym
#.include "../../mk/dlopen.buildlink3.mk"
#
.include "../../mk/bsd.pkg.mk"
