# $NetBSD: Makefile,v 1.4 2025/09/19 20:05:32 js Exp $

DISTNAME=	wimlib-1.14.4
PKGREVISION=	3
CATEGORIES=	sysutils devel
MASTER_SITES=	https://wimlib.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wimlib.net/
COMMENT=	Open source Windows Imaging (WIM) library and tools
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake bash:run

REPLACE_BASH=		programs/mkwinpeimg.in

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
