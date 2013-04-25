# $NetBSD: Makefile,v 1.1 2013/04/25 09:10:26 jperkin Exp $

DISTNAME=	jq-1.1
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/stedolan/jq/tarball/${DISTNAME}/

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

FETCH_USING=	curl

WRKSRC=		${WRKDIR}/stedolan-jq-bf61e95

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
