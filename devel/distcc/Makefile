# $NetBSD: Makefile,v 1.13 2004/02/01 02:23:24 jlam Exp $

DISTNAME=		distcc-2.12.1
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Tool for distributed C/C++ compiling

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-rfc2553
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	distcc

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
