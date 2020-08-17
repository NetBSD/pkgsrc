# $NetBSD: Makefile,v 1.60 2020/08/17 20:19:55 leot Exp $
#

DISTNAME=	gtklp-1.3.3
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtklp/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtklp.sourceforge.net/
COMMENT=	CUPS frontend using GTK

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt
MAKE_FLAGS+=		install_sh=${WRKSRC}/install-sh

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
