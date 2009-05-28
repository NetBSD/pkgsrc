# $NetBSD: Makefile,v 1.8 2009/05/28 21:08:54 zafer Exp $
#

DISTNAME=	libstree-0.4.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.icir.org/christian/libstree/
COMMENT=	Suffix tree library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

.include "../../mk/bsd.pkg.mk"
