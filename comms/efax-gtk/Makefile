# $NetBSD: Makefile,v 1.23 2005/12/05 23:55:03 rillig Exp $

DISTNAME=	efax-gtk-3.0.6.src
PKGNAME=	efax-gtk-3.0.6
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=efax-gtk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://efax-gtk.sourceforge.net/
COMMENT=	GTK frontend for efax

DEPENDS+=	efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
