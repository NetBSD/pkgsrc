# $NetBSD: Makefile,v 1.5 2001/02/05 09:01:01 tron Exp $
#

DISTNAME=		jwhois-2.4.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoremake:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/share/autoconf/gettext.m4:../../devel/gettext

GNU_CONFIGURE=		# defined
USE_LIBINTL=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=/var/db
CONFIGURE_ARGS+=	--with-cache

INFO_FILES=		jwhois.info

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoremake

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share/examples
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
