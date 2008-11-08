# $NetBSD: Makefile,v 1.23 2008/11/08 12:55:21 bjs Exp $

DISTNAME=	mhash-0.9.9
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

.include "../../mk/bsd.pkg.mk"
