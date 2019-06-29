# $NetBSD: Makefile,v 1.11 2019/06/29 17:46:55 gutteridge Exp $

DISTNAME=	link-grammar-5.6.2
CATEGORIES=	textproc
MASTER_SITES=	https://www.abisource.com/downloads/link-grammar/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-java-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
