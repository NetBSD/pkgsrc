# $NetBSD: Makefile,v 1.8 2003/03/09 13:26:54 jmmv Exp $
#

DISTNAME=	fcpackage.2_1
PKGNAME=	fontconfig-2.1
PKGREVISION=	4
CATEGORIES=	fonts gnome
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

# This can use 2.0.5 but things which use it (ala pango) require 2.0.9 so make
# sure to keep in step
BUILDLINK_DEPENDS.freetype2?=  freetype2>=2.0.9

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES
USE_X11=		YES

PKG_SYSCONFSUBDIR=	fontconfig

CONFIGURE_ARGS+=	--with-default-fonts=${LOCALBASE}/lib/X11/fonts
CONFIGURE_ARGS+=	--with-freetype-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CONFIGURE_ARGS+=	--with-freetype-lib=${BUILDLINK_PREFIX.freetype2}/lib
CONFIGURE_ARGS+=	--with-expat-includes=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expat-lib=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-x

EGDIR=		${PREFIX}/share/examples/fontconfig
CONF_FILES=	${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf
CONF_FILES+=	${EGDIR}/fonts.dtd ${PKG_SYSCONFDIR}/fonts.dtd

WRKSRC=		${WRKDIR}/${DISTNAME}/fontconfig

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/fontconfig.man \
	    ${PREFIX}/man/man3/fontconfig.3
.for f in fc-cache fc-list
	${INSTALL_MAN} ${WRKSRC}/$f/$f.man ${PREFIX}/man/man1/$f.1
.endfor

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
