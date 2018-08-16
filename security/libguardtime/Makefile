# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:31 adam Exp $

DISTNAME=	libgt-0.3.13
PKGNAME=	${DISTNAME:S/gt/guardtime/}
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://download.guardtime.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.guardtime.com/
COMMENT=	GuardTime Client C SDK
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

GNU_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-cadir=${SSLCERTS}

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
