# $NetBSD: Makefile,v 1.27 2004/10/03 00:14:50 tv Exp $
#

DISTNAME=		fnlib-0.5
PKGREVISION=		7
CATEGORIES=		x11 graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		root@garbled.net
COMMENT=		Color font rendering library for X11R6

# XXX Added to stop old distfiles conflicting due to the authors updating
# XXX fnlib-0.5.tar.gz without changing the filename.
# XXX Delete when DISTNAME next changes
DIST_SUBDIR=		fnlib

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"
EGDIR=			${PREFIX}/share/examples/fnlib
CONF_FILES=		${EGDIR}/fnrc ${PKG_SYSCONFDIR}/fnrc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fnlib
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${PREFIX}/share/doc/fnlib

.include "../../graphics/imlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
