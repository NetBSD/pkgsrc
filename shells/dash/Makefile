# $NetBSD: Makefile,v 1.6 2012/04/26 16:04:38 cheusov Exp $
#

DISTNAME=	dash-0.5.5.1
PKGREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/files/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKG_SHELL=		bin/dash

.include "../../mk/bsd.pkg.mk"
