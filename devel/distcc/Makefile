# $NetBSD: Makefile,v 1.10 2003/12/21 09:49:25 jmmv Exp $

DISTNAME=		distcc-2.12
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Tool for distributed C/C++ compiling

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS=		--enable-rfc2553
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	distcc

.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
