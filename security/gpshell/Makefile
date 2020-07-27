# $NetBSD: Makefile,v 1.6 2020/07/27 16:22:46 gdt Exp $

DISTNAME=	gpshell-1.4.4
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=globalplatform/GPShell/GPShell-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://globalplatform.sourceforge.net/
COMMENT=	Shell to manage the contents of GlobalPlatform smart cards
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/libglobalplatform/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
