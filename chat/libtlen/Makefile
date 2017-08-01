# $NetBSD: Makefile,v 1.13 2017/08/01 10:41:45 nros Exp $

DISTNAME=	libtlen-20041113
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libtlen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libtlen.sourceforge.net/
COMMENT=	Library to access tlen.pl IM system

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	lib

# package uses BSD-style non-blocking IO.
CPPFLAGS.SunOS+=	-DBSD_COMP=1

.include "../../mk/bsd.pkg.mk"
