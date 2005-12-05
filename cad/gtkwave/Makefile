# $NetBSD: Makefile,v 1.13 2005/12/05 20:49:51 rillig Exp $
#

DISTNAME=		gtkwave-2.0.0pre5
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.man.ac.uk/apt/tools/gtkwave/index.html
COMMENT=		Electronic waveform viewer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
