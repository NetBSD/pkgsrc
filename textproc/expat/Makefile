# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 12:13:04 drochner Exp $
#

DISTNAME=	expat-1.95.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/conftools/ltconfig

.include "../../mk/bsd.pkg.mk"
