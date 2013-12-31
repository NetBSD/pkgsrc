# $NetBSD: Makefile,v 1.2 2013/12/31 15:41:17 rodent Exp $
#

DISTNAME=	libticables2-1.3.3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Multi-platform linking program for TI graphing calculators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool msgfmt msgmerge pkg-config xgettext
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ticables2.pc.in

.include "options.mk"

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
