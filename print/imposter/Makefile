# $NetBSD: Makefile,v 1.16 2009/08/26 19:58:14 sno Exp $
#

DISTNAME=	imposter-0.3
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
