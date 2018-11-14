# $NetBSD: Makefile,v 1.47 2018/11/14 22:21:01 kleink Exp $
#

DISTNAME=	glurp-0.12.3
PKGREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

LIBS.SunOS+=	-lsocket -lnsl

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
