# $NetBSD: Makefile,v 1.4 2002/12/25 13:18:24 jmmv Exp $

DISTNAME=		efax-gtk-1.0.1b.src
PKGNAME=		efax-gtk-1.0.1b
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		http://www.cvine.freeserve.co.uk/efax-gtk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cvine.freeserve.co.uk/efax-gtk/
COMMENT=		GTK frontend for efax

DEPENDS+=		efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/efax-gtk
GNU_CONFIGURE=		YES
USE_BUILDLINK2= 	YES

CONFIGURE_ARGS+=	--with-spooldir=/var/spool/efax
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/efax-gtk
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

ALL_TARGET=		efax-gtk

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/efax-gtk.1.gz

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/efax-gtk

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
