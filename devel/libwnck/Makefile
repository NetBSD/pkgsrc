# $NetBSD: Makefile,v 1.3 2002/11/30 23:21:38 salo Exp $
#

DISTNAME=	libwnck-0.17
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/0.17/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library to write pagers and tasklists

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
