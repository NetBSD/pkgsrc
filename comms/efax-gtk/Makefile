# $NetBSD: Makefile,v 1.8 2003/05/02 11:54:08 wiz Exp $

DISTNAME=		efax-gtk-1.0.1b.src
PKGNAME=		efax-gtk-1.0.1b
PKGREVISION=		4
WRKSRC=			${WRKDIR}/efax-gtk
CATEGORIES=		comms
MASTER_SITES=		http://www.cvine.freeserve.co.uk/efax-gtk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cvine.freeserve.co.uk/efax-gtk/
COMMENT=		GTK frontend for efax

DEPENDS+=		efax>=0.9:../../comms/efax

GNU_CONFIGURE=		YES
USE_BUILDLINK2= 	YES
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--with-spooldir=/var/spool/efax
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/efax-gtk
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

ALL_TARGET=		efax-gtk

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/efax-gtk.1.gz

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/efax-gtk

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
