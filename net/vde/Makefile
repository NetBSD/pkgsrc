# $NetBSD: Makefile,v 1.6 2020/01/18 23:33:22 rillig Exp $
#

DISTNAME=		vde-1.5.9
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vde/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://vde.sourceforge.net/
COMMENT=		Virtual Distributed Ethernet tools
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
