# $NetBSD: Makefile,v 1.5 2022/07/25 11:12:22 wiz Exp $

DISTNAME=		libestr-0.1.11
CATEGORIES=		devel
MASTER_SITES=		https://libestr.adiscon.com/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://libestr.adiscon.com/
COMMENT=		Library for some string essentials
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libestr.pc.in

.include "../../mk/bsd.pkg.mk"
