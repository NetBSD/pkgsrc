# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 13:23:51 agc Exp $
#

DISTNAME=		xlHtml-0.2.8
CATEGORIES=		converters
MASTER_SITES=		http://www.xlHtml.org/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xlHtml.org/
COMMENT=		Microsoft xls/ppt to HTML converter

BUILD_DEPENDS+=		autoconf-*:../../devel/autoconf
BUILD_DEPENDS+=		automake-*:../../devel/automake

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
