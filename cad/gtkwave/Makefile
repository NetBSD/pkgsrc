# $NetBSD: Makefile,v 1.16 2006/10/04 20:47:44 wiz Exp $
#

DISTNAME=		gtkwave-2.0.0pre5
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.manchester.ac.uk/apt/projects/tools/gtkwave/
COMMENT=		Electronic waveform viewer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
