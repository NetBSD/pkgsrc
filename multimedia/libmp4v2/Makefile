# $NetBSD: Makefile,v 1.1.1.1 2007/02/09 19:57:48 drochner Exp $

DISTNAME=		mpeg4ip-1.5.0.1
PKGNAME=		libmp4v2-1.5.0.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		libmp4v2 from mpeg4ip

CONFLICTS+=		mpeg4ip<1.5.0.1

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap

BUILD_DIRS=		lib/mp4v2
INSTALL_DIRS+=		lib/mp4v2 doc/mp4v2

.include "../../mk/bsd.pkg.mk"
