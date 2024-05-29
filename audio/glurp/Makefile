# $NetBSD: Makefile,v 1.67 2024/05/29 16:31:20 adam Exp $
#

DISTNAME=	glurp-0.12.3
PKGREVISION=	39
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-export-dynamic

LIBS.SunOS+=	-lsocket -lnsl

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
