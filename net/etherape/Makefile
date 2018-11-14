# $NetBSD: Makefile,v 1.101 2018/11/14 22:22:10 kleink Exp $

DISTNAME=	etherape-0.9.12
PKGREVISION=	35
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	Graphical network monitor
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	etherape

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/etherape

CONF_FILES=	${EGDIR}/services ${PKG_SYSCONFDIR}/services

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
