# $NetBSD: Makefile,v 1.5 2021/12/08 16:01:46 adam Exp $
#

DISTNAME=	libticables2-1.3.3
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
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
