# $NetBSD: Makefile,v 1.2 2005/02/26 13:26:05 dsainty Exp $
#

DISTNAME=	ppower-0.1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppower/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://ppower.sourceforge.net/
COMMENT=	X10 controller software for the CM11A interface

#LICENSE=       	GPL

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ppower
	${INSTALL_DATA} \
		${WRKSRC}/etc/ppower.conf ${PREFIX}/share/examples/ppower

.include "../../mk/bsd.pkg.mk"
