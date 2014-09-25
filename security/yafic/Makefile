# $NetBSD: Makefile,v 1.8 2014/09/25 19:27:18 jperkin Exp $

DISTNAME=	yafic-1.2.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.saddi.com/software/yafic/
COMMENT=	File integrity checker
LICENSE=	modified-bsd

GNU_CONFIGURE=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
