# $NetBSD: Makefile,v 1.23 2008/07/14 12:55:57 joerg Exp $
#

DISTNAME=	libsidplay-1.36.59
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://tnsp.org/xs-files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/?p=libsidplay1
COMMENT=	Sidplay Library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
