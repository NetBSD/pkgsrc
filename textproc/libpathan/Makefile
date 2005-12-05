# $NetBSD: Makefile,v 1.10 2005/12/05 20:51:05 rillig Exp $

DISTNAME=	libpathan-1.2-2-src
PKGNAME=	${DISTNAME:S/-2-src/.2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/pathan-1.2r2/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://software.decisionsoft.com/
COMMENT=	Library to parse and evaluate XPath expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-2-src//}
GNU_CONFIGURE=		YES
USE_TOOLS+=		bison gmake perl
USE_LIBTOOL=		YES
USE_LANGUAGES=		c++

CONFIGURE_ARGS+=	XERCESCROOT=${LOCALBASE:Q}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
