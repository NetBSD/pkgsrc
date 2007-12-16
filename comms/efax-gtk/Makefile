# $NetBSD: Makefile,v 1.39 2007/12/16 16:41:47 adam Exp $

DISTNAME=	efax-gtk-3.0.16.src
PKGNAME=	efax-gtk-3.0.16
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=efax-gtk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://efax-gtk.sourceforge.net/
COMMENT=	GTK frontend for efax

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
