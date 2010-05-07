# $NetBSD: Makefile,v 1.4 2010/05/07 12:02:44 jmmv Exp $
#

DISTNAME=	dash-0.5.5.1
PKGREVISION=	2
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
