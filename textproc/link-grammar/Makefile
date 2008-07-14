# $NetBSD: Makefile,v 1.2 2008/07/14 12:56:13 joerg Exp $
#

DISTNAME=	link-grammar-4.3.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/link-grammar/4.3.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
