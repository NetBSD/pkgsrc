# $NetBSD: Makefile,v 1.30 2006/05/15 19:14:49 joerg Exp $

DISTNAME=	efax-gtk-3.0.8.src
PKGNAME=	efax-gtk-3.0.8
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=efax-gtk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://efax-gtk.sourceforge.net/
COMMENT=	GTK frontend for efax

DEPENDS+=	efax>=0.9:../../comms/efax

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
