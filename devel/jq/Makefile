# $NetBSD: Makefile,v 1.4 2014/04/17 09:08:34 fhajny Exp $

DISTNAME=	jq-1.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/stedolan/jq/archive/

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

WRKSRC=		${WRKDIR}/jq-${DISTNAME}

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf bison flex gmake

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
