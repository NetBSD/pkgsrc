# $NetBSD: Makefile,v 1.6 2012/09/07 19:16:19 adam Exp $
#

DISTNAME=	gtkdbfeditor-1.0.4
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdbfeditor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdteffen.de/gtkdbfeditor/
COMMENT=	Simple editor for DBF files (dBase, xBase)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
