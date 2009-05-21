# $NetBSD: Makefile,v 1.4 2009/05/21 11:41:09 zafer Exp $

DISTNAME=		mbrowse-0.3.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_FREEBSD}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.kill-9.org/mbrowse/
COMMENT=		Graphical SNMP MIB browser

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-snmp-prefix=${BUILDLINK_PREFIX.net-snmp:Q}

pre-configure:
	@ ${TEST} -r ${PKGDIR}/../../mk/gnu-config/missing && \
	  ${CP} -f ${PKGDIR}/../../mk/gnu-config/missing ${WRKSRC}

.include "../../net/net-snmp/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
