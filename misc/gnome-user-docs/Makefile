# $NetBSD: Makefile,v 1.21 2009/12/02 18:44:11 snj Exp $

DISTNAME=	gnome-user-docs-2.28.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-user-docs/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	The GNOME 2 users guide
LICENSE=	gnu-fdl-v1.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gnome2-user-docs-[0-9]*

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
