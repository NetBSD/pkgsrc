# $NetBSD: Makefile,v 1.29 2004/01/24 14:50:05 grant Exp $
#

DISTNAME=	gtk-gnutella-0.92
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtk-gnutella
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtk-gnutella

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
