# $NetBSD: Makefile,v 1.9 2009/07/17 18:00:19 adrianp Exp $

DISTNAME=	netcat-0.7.1
PKGNAME=	gnetcat-0.7.1
PKGREVISION=	2
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netcat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://netcat.sourceforge.net/
COMMENT=	Read and write data across network connections

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
INFO_FILES=		yes
USE_TOOLS+=		msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
