# $NetBSD: Makefile,v 1.9 2017/07/30 22:47:52 wiz Exp $
#

DISTNAME=	gnome-devel-docs-2.26.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-devel-docs/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	The GNOME 2 developer's guide
LICENSE=	gnu-fdl-v1.1

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
