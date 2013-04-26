# $NetBSD: Makefile,v 1.2 2013/04/26 10:20:34 jperkin Exp $

DISTNAME=	jq-1.2
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/stedolan/jq/tarball/${DISTNAME}/

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

FETCH_USING=	curl

WRKSRC=		${WRKDIR}/stedolan-jq-1e8c524

USE_LANGUAGES=	c99
USE_TOOLS+=	bison flex gmake

NO_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6

.include "../../mk/bsd.pkg.mk"
