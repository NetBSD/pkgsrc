# $NetBSD: Makefile,v 1.3 2002/09/11 23:45:13 wiz Exp $

DISTNAME=		efax-gtk-1.0.1b.src
PKGNAME=		efax-gtk-1.0.1b
PKGREVISION=		1
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

ALL_TARGET=		efax-gtk

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/efax-gtk.1.gz

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
