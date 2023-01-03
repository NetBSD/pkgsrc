# $NetBSD: Makefile,v 1.66 2023/01/03 17:38:07 wiz Exp $
#

DISTNAME=	gtklp-1.3.3
PKGREVISION=	14
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
