# $NetBSD: Makefile,v 1.1.1.1 2003/02/15 12:34:06 martti Exp $

DISTNAME=		distcc-1.1
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		teemu@rinta-aho.org
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Tool for distributed C/C++ compiling

## USE_BUILDLINK2=	YES
## USE_LIBTOOL=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
