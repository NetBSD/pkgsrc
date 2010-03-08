# $NetBSD: Makefile,v 1.5 2010/03/08 14:01:21 joerg Exp $
#

DISTNAME=	vala-0.7.10
CATEGORIES=	lang gnome
MASTER_SITES=	http://download.gnome.org/sources/vala/0.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system

LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	vala-1.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=                   glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=                    gtk2+>=2.10.0
BUILDLINK_DEPMETHOD.libxslt?=			build

INSTALLATION_DIRS=     share/doc/vala

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/vala

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
