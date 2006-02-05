# $NetBSD: Makefile,v 1.17 2006/02/05 23:10:09 joerg Exp $
#

DISTNAME=	gnome2-user-docs-2.8.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome2-user-docs/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	The GNOME 2 users guide

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
