# $NetBSD: Makefile,v 1.11 2006/04/05 23:01:15 jlam Exp $

DISTNAME=	blitz-0.8
PKGNAME=	blitz++-0.8
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oonumerics.org/blitz/
COMMENT=	C++ template class library providing array objects

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cxx=gcc
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
