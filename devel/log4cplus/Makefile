# $NetBSD: Makefile,v 1.3 2012/11/16 00:44:34 joerg Exp $
#

DISTNAME=	log4cplus-1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=log4cplus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://log4cplus.sourceforge.net/
COMMENT=	Logging API for C++
LICENSE=	apache-2.0 AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++	# C for configure

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=	-Werror=ignored-attributes
.endif

.include "../../mk/bsd.pkg.mk"
