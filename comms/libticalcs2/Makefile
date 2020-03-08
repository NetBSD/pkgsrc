# $NetBSD: Makefile,v 1.3 2020/03/08 16:47:28 wiz Exp $
#

DISTNAME=	libticalcs2-1.1.7
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Multi-platform linking program for TI graphing calculators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt msgmerge pkg-config xgettext
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ticalcs2.pc.in

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/libtifiles2/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../comms/libticables2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
