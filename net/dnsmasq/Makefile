# $NetBSD: Makefile,v 1.15 2010/11/27 13:24:47 roy Exp $
#

DISTNAME=		dnsmasq-2.55
CATEGORIES=		net
MASTER_SITES=		http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://www.thekelleys.org.uk/dnsmasq/doc.html
COMMENT=		Lightweight, easy to configure DNS forwarder

RCD_SCRIPTS=		dnsmasq
CONF_FILES=		${PREFIX}/share/examples/dnsmasq/dnsmasq.conf.example \
			${PKG_SYSCONFDIR}/dnsmasq.conf

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

# Override the defaults
AUTO_MKDIRS=yes
CFLAGS+=		-DCONFFILE=\\\"${PKG_SYSCONFDIR}/dnsmasq.conf\\\"
BUILD_MAKE_FLAGS+=	COPTS="${CFLAGS}"
INSTALL_MAKE_FLAGS+=	PREFIX="${PREFIX}"
INSTALL_MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"
INSTALL_MAKE_FLAGS+=	LOCALEDIR="${PREFIX}/${PKGLOCALEDIR}"

# Upstream wants to use nawk, but awk should work just fine here.
BUILD_MAKE_FLAGS+=	AWK="${AWK}"
INSTALL_MAKE_FLAGS+=	AWK="${AWK}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example \
		${DESTDIR}${PREFIX}/share/examples/dnsmasq/

.include "../../mk/bsd.pkg.mk"
