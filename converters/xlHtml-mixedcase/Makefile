# $NetBSD: Makefile,v 1.5 2001/11/29 19:46:10 jlam Exp $
#

DISTNAME=		xlHtml-0.2.8
CATEGORIES=		converters
MASTER_SITES=		http://www.xlHtml.org/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xlHtml.org/
COMMENT=		Microsoft xls/ppt to HTML converter

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
