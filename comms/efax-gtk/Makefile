# $NetBSD: Makefile,v 1.13 2004/04/26 22:07:06 snj Exp $

DISTNAME=		efax-gtk-1.0.1b.src
PKGNAME=		efax-gtk-1.0.1b
PKGREVISION=		5
CATEGORIES=		comms
MASTER_SITES=		http://www.cvine.freeserve.co.uk/efax-gtk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cvine.freeserve.co.uk/efax-gtk/
COMMENT=		GTK frontend for efax

DEPENDS+=		efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/efax-gtk
GNU_CONFIGURE=		YES
USE_BUILDLINK3= 	YES
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

.include "../../devel/libsigc++10/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtk--/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
