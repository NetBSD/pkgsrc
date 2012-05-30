# $NetBSD: Makefile,v 1.7 2012/05/30 20:33:26 cheusov Exp $
#

DISTNAME=	dash-0.5.7
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/files/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash
LICENSE=	modified-bsd AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKG_SHELL=		bin/dash

.include "../../mk/bsd.pkg.mk"
