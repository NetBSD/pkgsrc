# $NetBSD: Makefile,v 1.25 2012/09/07 19:16:08 adam Exp $
#

DISTNAME=	glurp-0.12.3
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

LIBS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-export-dynamic
.endif

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
