# $NetBSD: Makefile,v 1.6 2005/07/01 04:31:05 grant Exp $

DISTNAME=	libtlen-20040912
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.libtlen.eu.org/snapshots/archive/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.libtlen.eu.org/
COMMENT=	Library to access tlen.pl IM system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	lib

# package uses BSD-style non-blocking IO.
CPPFLAGS.SunOS+=	-DBSD_COMP=1

.include "../../mk/bsd.pkg.mk"
