# $NetBSD: Makefile,v 1.13 2001/10/31 15:08:29 tv Exp $
#

DISTNAME=		jwhois-3.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/usr/pkg/etc
CONFIGURE_ARGS+=	--localstatedir=/var/db
CONFIGURE_ARGS+=	--with-cache

INFO_FILES=		jwhois.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share/examples
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
