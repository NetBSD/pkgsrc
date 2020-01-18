# $NetBSD: Makefile,v 1.21 2020/01/18 23:30:32 rillig Exp $

DISTNAME=	libntlm-1.5
CATEGORIES=	security
MASTER_SITES=	http://www.nongnu.org/libntlm/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/libntlm/
COMMENT=	Library that implement Microsoft's NTLM authentication
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libntlm.pc.in

.include "../../mk/bsd.pkg.mk"
