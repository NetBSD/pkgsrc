# $NetBSD: Makefile,v 1.15 2002/04/15 06:59:23 martti Exp $
#

DISTNAME=		gtk-gnutella-0.85
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTk-based gnutella client

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtk-gnutella
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtk-gnutella

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
