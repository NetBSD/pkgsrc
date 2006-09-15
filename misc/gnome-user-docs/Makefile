# $NetBSD: Makefile,v 1.4 2006/09/15 15:23:39 jmmv Exp $
#

DISTNAME=	gnome-user-docs-2.16.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-user-docs/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	The GNOME 2 users guide

CONFLICTS+=		gnome2-user-docs-[0-9]*

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
