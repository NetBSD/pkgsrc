# $NetBSD: Makefile,v 1.19 2002/10/29 22:35:38 rh Exp $
#

DISTNAME=		gtk-gnutella-0.91
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTk-based gnutella client

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtk-gnutella
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtk-gnutella

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
