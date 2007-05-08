# $NetBSD: Makefile,v 1.21 2007/05/08 15:51:32 joerg Exp $

DISTNAME=	mhash-0.9.9
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

.include "../../mk/bsd.pkg.mk"
