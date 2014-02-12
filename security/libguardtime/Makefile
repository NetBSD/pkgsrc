# $NetBSD: Makefile,v 1.2 2014/02/12 23:18:33 tron Exp $

DISTNAME=	libgt-0.3.11-src
PKGNAME=	libguardtime-0.3.11
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://download.guardtime.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.guardtime.com/
COMMENT=	GuardTime Client C SDK
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

GNU_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
