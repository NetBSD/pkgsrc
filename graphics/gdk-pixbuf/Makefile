# $NetBSD: Makefile,v 1.8 2000/10/17 23:59:59 jlam Exp $
#

DISTNAME=		gdk-pixbuf-0.9.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gdk-pixbuf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.0.53:../../x11/gnome-libs

USE_X11BASE=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.prefs.mk"
.if (${OBJECT_FMT} == "ELF")
PLIST_SRC=		${PKGDIR}/PLIST.elf
.endif
PLIST_SRC+=		${PKGDIR}/PLIST.mi

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
		${LOCALBASE}/share/aclocal/libart.m4

.include "../../mk/bsd.pkg.mk"
