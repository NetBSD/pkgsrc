# $NetBSD: Makefile,v 1.51 2014/05/15 14:41:51 adam Exp $
#

DISTNAME=		fnlib-0.5
PKGREVISION=		21
CATEGORIES=		x11 graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Color font rendering library for X11R6

# XXX Added to stop old distfiles conflicting due to the authors updating
# XXX fnlib-0.5.tar.gz without changing the filename.
# XXX Delete when DISTNAME next changes
DIST_SUBDIR=		fnlib

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
EGDIR=			${PREFIX}/share/examples/fnlib
CONF_FILES=		${EGDIR}/fnrc ${PKG_SYSCONFDIR}/fnrc

INSTALLATION_DIRS+=	share/doc/fnlib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${DESTDIR}${PREFIX}/share/doc/fnlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
