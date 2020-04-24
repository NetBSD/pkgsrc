# $NetBSD: Makefile,v 1.12 2020/04/24 11:41:38 nia Exp $

DISTNAME=	yafic-1.2.2
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.saddi.com/software/yafic/
COMMENT=	File integrity checker
LICENSE=	modified-bsd

BROKEN=		"Fails to build with OpenSSL 1.1"

GNU_CONFIGURE=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
