# $NetBSD: Makefile,v 1.18 2012/10/31 11:17:18 asau Exp $

DISTNAME=	libntlm-1.2
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/libntlm/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://josefsson.org/libntlm/
COMMENT=	Library that implement Microsoft's NTLM authentication
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libntlm.pc.in

.include "../../mk/bsd.pkg.mk"
