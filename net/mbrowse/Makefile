# $NetBSD: Makefile,v 1.2 2006/05/06 17:12:33 heinz Exp $

DISTNAME=		mbrowse-0.3.1
CATEGORIES=		net
MASTER_SITES=		http://www.kill-9.org/mbrowse/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.kill-9.org/mbrowse/
COMMENT=		Graphical SNMP MIB browser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-snmp-prefix=${PREFIX:Q}

pre-configure:
	@ ${TEST} -r ${PKGDIR}/../../mk/gnu-config/missing && \
	  ${CP} -f ${PKGDIR}/../../mk/gnu-config/missing ${WRKSRC}

.include "../../net/net-snmp/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
