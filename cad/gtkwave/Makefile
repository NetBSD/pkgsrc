# $NetBSD: Makefile,v 1.1.1.1 2003/07/14 13:21:18 drochner Exp $
#

DISTNAME=		gtkwave-2.0.0pre3
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
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
