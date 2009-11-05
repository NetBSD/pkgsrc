# $NetBSD: Makefile,v 1.3 2009/11/05 21:56:59 asau Exp $
#

DISTNAME=	dash-0.5.5.1
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/files/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKG_SHELL=		bin/dash

.include "../../mk/bsd.pkg.mk"
