# $NetBSD: Makefile,v 1.2 2001/08/19 19:09:40 jlam Exp $
#

DISTNAME=		xlHtml-0.2.8
CATEGORIES=		converters
MASTER_SITES=		http://www.xlHtml.org/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xlHtml.org/
COMMENT=		Microsoft xls/ppt to HTML converter

BUILD_DEPENDS+=		autoconf-*:../../devel/autoconf
BUILD_DEPENDS+=		automake-*:../../devel/automake

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
