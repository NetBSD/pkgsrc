# $NetBSD: Makefile,v 1.37 2004/12/28 11:02:55 tron Exp $

DISTNAME=	gtk-gnutella-0.95
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d -e -r -s -D prefix="${PREFIX}" -D cc="${CC}" \
			-D privlib="${PREFIX}/share/gtk-gnutella" \
			-D sysman="${PREFIX}/man" -D cflags="${CFLAGS}" \
			-D locale="${PREFIX}/${PKGLOCALEDIR}/locale" \
			-D optimize="${COPTS}" -D gtkversion=2 -D yacc="yacc"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-configure:
	@if [ -f ${BUILDLINK_PREFIX.gtk2}/include/gtk-2.0/gtk/gtkcellrendererprogress.h ]; then \
	  cd ${WRKSRC}/src/ui/gtk/gtk2 && 			\
	  ${RM} pbarcellrenderer.c pbarcellrenderer.h &&	\
	  ${TOUCH} pbarcellrenderer.c pbarcellrenderer.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
