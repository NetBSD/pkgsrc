# $NetBSD: Makefile,v 1.2 2017/09/03 08:53:07 wiz Exp $

DISTNAME=	mcpp-2.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcpp/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mcpp/files/mcpp/V.2.7.2/
COMMENT=	Portable C/C++ preprocessor
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-mcpplib

.include "../../mk/bsd.pkg.mk"
