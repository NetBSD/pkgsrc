# $NetBSD: Makefile,v 1.2 2007/02/16 00:56:40 wiz Exp $

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
# the "bootstrap" script checks too much, and isn't useful anyway
#CONFIGURE_SCRIPT=	bootstrap

BUILD_DIRS=		lib/mp4v2
INSTALL_DIRS+=		lib/mp4v2 doc/mp4v2

pre-configure:
	${TOUCH} ${WRKSRC}/bootstrapped

.include "../../mk/bsd.pkg.mk"
