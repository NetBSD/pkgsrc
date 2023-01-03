# $NetBSD: Makefile,v 1.36 2023/01/03 17:36:53 wiz Exp $
#

DISTNAME=	gtkdbfeditor-1.0.4
PKGREVISION=	33
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdbfeditor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdteffen.de/gtkdbfeditor/
COMMENT=	Simple editor for DBF files (dBase, xBase)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
