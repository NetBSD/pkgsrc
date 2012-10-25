# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:05 asau Exp $

DISTNAME=	link-grammar-4.7.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/link-grammar/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
