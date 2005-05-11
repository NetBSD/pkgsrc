# $NetBSD: Makefile,v 1.40 2005/05/11 09:50:11 adam Exp $

DISTNAME=	gtk-gnutella-0.95.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client

USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d -e -r -s \
			-D prefix="${PREFIX}" \
			-D privlib="${PREFIX}/share/gtk-gnutella" \
			-D sysman="${PREFIX}/man" \
			-D locale="${PREFIX}/${PKGLOCALEDIR}/locale" \
			-D cc="${CC}" \
			-D ccflags="${CFLAGS:Unone}" \
			-D gtkversion=2 \
			-D yacc="yacc" \
			-D official="true" \
			-U optimize

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-configure:
	cd "${WRKSRC}/src/ui/gtk/gtk2" && \
	${TOUCH} interface-glade.c interface-glade.h \
		support-glade.c support-glade.h

.include "../../mk/bsd.pkg.mk"
