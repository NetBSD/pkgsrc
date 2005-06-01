# $NetBSD: Makefile,v 1.43 2005/06/01 18:03:07 jlam Exp $

DISTNAME=	gtk-gnutella-0.95.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
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
.include "../../mk/bsd.pkg.mk"
