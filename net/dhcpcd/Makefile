# $NetBSD: Makefile,v 1.24 2010/07/07 22:03:37 roy Exp $
#

DISTNAME=		dhcpcd-5.2.6
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		RFC2131 compliant DHCP client
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hooks=ntp

EGDIR=			${PREFIX}/share/examples
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpcd

.include "../../mk/bsd.pkg.mk"
