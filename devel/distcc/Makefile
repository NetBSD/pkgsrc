# $NetBSD: Makefile,v 1.9 2003/12/12 23:10:57 jmmv Exp $

DISTNAME=		distcc-2.11.2
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Tool for distributed C/C++ compiling

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	distcc

.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
