# $NetBSD: Makefile,v 1.11 2012/10/03 00:02:40 asau Exp $

DISTNAME=	libtlen-20041113
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libtlen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libtlen.sourceforge.net/
COMMENT=	Library to access tlen.pl IM system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	lib

# package uses BSD-style non-blocking IO.
CPPFLAGS.SunOS+=	-DBSD_COMP=1

.include "../../mk/bsd.pkg.mk"
