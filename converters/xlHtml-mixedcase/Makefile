# $NetBSD: Makefile,v 1.4 2001/09/27 23:17:51 jlam Exp $
#

DISTNAME=		xlHtml-0.2.8
CATEGORIES=		converters
MASTER_SITES=		http://www.xlHtml.org/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xlHtml.org/
COMMENT=		Microsoft xls/ppt to HTML converter

BUILD_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
