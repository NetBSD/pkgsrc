# $NetBSD: Makefile,v 1.5 2003/04/27 14:35:34 cjep Exp $
#

DISTNAME=	etherape-0.9.0
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	graphical network monitor

USE_GMAKE=		YES
USE_X11=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	etherape

# XXX: $localedir defaults to $libdir/locale
CONFIGURE_ARGS+=	--libdir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/etherape

CONF_FILES=	${EGDIR}/services ${PKG_SYSCONFDIR}/services

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/services ${EGDIR}

.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
