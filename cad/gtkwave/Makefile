# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:13 tv Exp $
#

#DISTNAME=		gtkwave-2.0.0pre3
DISTNAME=		gtkwave-2.0.0pre3-20030319
PKGNAME=		gtkwave-2.0.0pre3.20030319
PKGREVISION=		3
CATEGORIES=		cad
#MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/snapshots/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.man.ac.uk/apt/tools/gtkwave/index.html
COMMENT=		Electronic waveform viewer

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
