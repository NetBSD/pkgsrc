# $NetBSD: Makefile,v 1.1.1.1 2003/09/12 17:26:10 xtraeme Exp $
#

DISTNAME=	gnome2-user-docs-2.0.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome2-user-docs/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		The GNOME 2 users guide

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
