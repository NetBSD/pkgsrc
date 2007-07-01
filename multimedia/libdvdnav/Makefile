# $NetBSD: Makefile,v 1.7 2007/07/01 16:00:10 heinz Exp $
#

DISTNAME=	libdvdnav-0.1.10
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvd.sourceforge.net/
COMMENT=	Library to navigate DVDs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
