# $NetBSD: Makefile,v 1.4 2003/10/31 12:28:12 drochner Exp $
#

#DISTNAME=		gtkwave-2.0.0pre3
DISTNAME=		gtkwave-2.0.0pre3-20030319
PKGNAME=		gtkwave-2.0.0pre3.20030319
CATEGORIES=		cad
#MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
MASTER_SITES=	ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/snapshots/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.man.ac.uk/apt/tools/gtkwave/index.html
COMMENT=		Electronic waveform viewer

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
