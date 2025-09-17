# $NetBSD: Makefile,v 1.1 2025/09/17 14:31:41 js Exp $

DISTNAME=	wimlib-1.14.4
CATEGORIES=	sysutils devel
MASTER_SITES=	https://wimlib.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wimlib.net/
COMMENT=	Open source Windows Imaging (WIM) library and tools
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
