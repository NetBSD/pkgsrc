# $NetBSD: Makefile,v 1.9 2016/03/05 11:29:27 jperkin Exp $

DISTNAME=	yafic-1.2.2
PKGREVISION=	1
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
