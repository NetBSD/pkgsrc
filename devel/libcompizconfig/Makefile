# $NetBSD: Makefile,v 1.23 2012/10/31 11:17:11 asau Exp $
#

PKGVER=		0.8.4
DISTNAME=	libcompizconfig-${PKGVER}
PKGREVISION=	15
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Configuration backend for compiz
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool gmake xgettext msgmerge msgfmt
USE_LANGUAGES+=	c c++

PKG_SYSCONFSUBDIR?=	compizconfig
EGDIR=		${PREFIX}/share/examples/compizconfig
CONF_FILES+=	${EGDIR}/config ${PKG_SYSCONFDIR}/config

PKGCONFIG_OVERRIDE=	libcompizconfig.pc.in

INSTALLATION_DIRS=	${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
