# $NetBSD: Makefile,v 1.1.1.1 2008/04/14 22:24:17 wiz Exp $
#

DISTNAME=	link-grammar-4.3.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/link-grammar/4.3.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
