# $NetBSD: Makefile,v 1.37 2000/06/20 01:40:16 dmcmahill Exp $
#

DISTNAME=		imlib-1.9.8.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/imlib/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.labs.redhat.com/imlib/

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		netpbm-*:../../graphics/netpbm
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff>=3.5.4:../../graphics/tiff

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS=		-DENABLE_NLS
.endif

CPPFLAGS+=		-I${LOCALBASE}/include

.if ${OBJECT_FMT} == "a.out"
PLIST_SRC=	${PKGDIR}/PLIST.mi
.else
PLIST_SRC=	${PKGDIR}/PLIST.mi ${PKGDIR}/PLIST.elf
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/imlib.m4 \
		${LOCALBASE}/share/aclocal/imlib.m4

.include "../../mk/bsd.pkg.mk"
