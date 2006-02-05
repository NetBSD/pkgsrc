# $NetBSD: Makefile,v 1.27 2006/02/05 23:08:27 joerg Exp $

DISTNAME=	efax-gtk-3.0.8.src
PKGNAME=	efax-gtk-3.0.8
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=efax-gtk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://efax-gtk.sourceforge.net/
COMMENT=	GTK frontend for efax

DEPENDS+=	efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
