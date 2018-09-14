# $NetBSD: Makefile,v 1.8 2018/09/14 08:43:02 fhajny Exp $

DISTNAME=	link-grammar-5.3.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/link-grammar/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_LANGUAGES=	c c99 c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-java-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
