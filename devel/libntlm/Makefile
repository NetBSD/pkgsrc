# $NetBSD: Makefile,v 1.23 2022/07/25 11:12:23 wiz Exp $

DISTNAME=	libntlm-1.6
CATEGORIES=	devel security
MASTER_SITES=	http://www.nongnu.org/libntlm/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/libntlm/
COMMENT=	Library that implement Microsoft's NTLM authentication
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libntlm.pc.in

.include "../../mk/bsd.pkg.mk"
