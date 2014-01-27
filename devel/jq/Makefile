# $NetBSD: Makefile,v 1.3 2014/01/27 18:41:11 wiz Exp $

DISTNAME=	jq-1.2
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/stedolan/jq/tarball/${DISTNAME}/

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

WRKSRC=		${WRKDIR}/stedolan-jq-1e8c524

USE_LANGUAGES=	c99
USE_TOOLS+=	bison flex gmake

NO_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6

.include "../../mk/bsd.pkg.mk"
