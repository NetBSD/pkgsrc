# $NetBSD: Makefile,v 1.12 2011/01/11 20:06:09 gls Exp $
#

DISTNAME=	vala-0.10.2
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	libvala.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
BUILDLINK_DEPMETHOD.libxslt=			build

INSTALLATION_DIRS=		share/doc/vala

SUBST_CLASSES+=			bookdir
SUBST_STAGE.bookdir=	post-patch
SUBST_MESSAGE.bookdir=	Fixing doc path
SUBST_FILES.bookdir=	doc/vala/Makefile.in doc/vala/Makefile.am
SUBST_SED.bookdir=		-e 's,@@BOOKDIR@@,${PREFIX}/share/doc/vala/devhelp/books,'

post-install:
.for file in AUTHORS COPYING ChangeLog ChangeLog.pre-0-4 ChangeLog.pre-0-5-7 INSTALL MAINTAINERS NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${DESTDIR}${PREFIX}/share/doc/vala
.endfor

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
