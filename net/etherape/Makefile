# $NetBSD: Makefile,v 1.68 2012/09/07 19:17:19 adam Exp $

DISTNAME=	etherape-0.9.12
PKGREVISION=	8
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	Graphical network monitor

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	etherape

# XXX: $localedir defaults to $libdir/locale
GNU_CONFIGURE_LIBDIR=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/etherape

CONF_FILES=	${EGDIR}/services ${PKG_SYSCONFDIR}/services

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/services ${DESTDIR}${EGDIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
