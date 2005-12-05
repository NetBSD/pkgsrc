# $NetBSD: Makefile,v 1.4 2005/12/05 23:55:12 rillig Exp $
#

DISTNAME=	ppower-0.1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppower/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://ppower.sourceforge.net/
COMMENT=	X10 controller software for the CM11A interface

#LICENSE=       	GPL

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ppower
	${INSTALL_DATA} \
		${WRKSRC}/etc/ppower.conf ${PREFIX}/share/examples/ppower

.include "../../mk/bsd.pkg.mk"
