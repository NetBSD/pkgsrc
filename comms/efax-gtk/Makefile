# $NetBSD: Makefile,v 1.17 2005/03/30 13:49:28 adam Exp $

DISTNAME=	efax-gtk-2.2.15.src
PKGNAME=	efax-gtk-2.2.15
CATEGORIES=	comms
MASTER_SITES=	http://www.cvine.freeserve.co.uk/efax-gtk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cvine.freeserve.co.uk/efax-gtk/
COMMENT=	GTK frontend for efax

DEPENDS+=	efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_BUILDLINK3= 	yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
