# $NetBSD: Makefile,v 1.15 2024/02/22 08:39:26 adam Exp $

DISTNAME=	dash-0.5.12
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash
LICENSE=	modified-bsd AND gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKG_SHELL=		bin/dash

CONFIGURE_ARGS+=	--with-libedit

.include "../../devel/editline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
