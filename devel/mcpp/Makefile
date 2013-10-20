# $NetBSD: Makefile,v 1.1 2013/10/20 15:06:58 ryoon Exp $

DISTNAME=	mcpp-2.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcpp/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mcpp/files/mcpp/V.2.7.2/
COMMENT=	Portable C/C++ preprocessor
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-mcpplib

.include "../../mk/bsd.pkg.mk"
