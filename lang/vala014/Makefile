# $NetBSD: Makefile,v 1.5 2012/09/15 10:05:21 obache Exp $
#

DISTNAME=	vala-0.14.2
PKGNAME=	vala014-0.14.2
PKGREVISION=	3
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.14/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system (0.14 branch)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	vala<0.12.1nb1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-vapigen
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

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
