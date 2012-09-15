# $NetBSD: Makefile,v 1.28 2012/09/15 10:06:10 obache Exp $
#

DISTNAME=	imposter-0.3
PKGREVISION=	14
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

LDFLAGS.DragonFly=	-lm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
