# $NetBSD: Makefile,v 1.2 2002/12/12 22:30:14 jmmv Exp $
#

DISTNAME=	fcpackage.2_1
PKGNAME=	fontconfig-2.1
PKGREVISION=	1
CATEGORIES=	fonts gnome
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
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

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
