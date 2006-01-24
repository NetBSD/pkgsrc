# $NetBSD: Makefile,v 1.33 2006/01/24 07:32:29 wiz Exp $

DISTNAME=	etherape-0.9.1
PKGREVISION=	3
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	Graphical network monitor

USE_TOOLS+=		gmake pkg-config
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	etherape

# XXX: $localedir defaults to $libdir/locale
CONFIGURE_ARGS+=	--libdir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/etherape

CONF_FILES=	${EGDIR}/services ${PKG_SYSCONFDIR}/services

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/services ${EGDIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
