# $NetBSD: Makefile,v 1.12 2006/07/22 04:46:18 rillig Exp $

DISTNAME=	libpathan-1.2-2-src
PKGNAME=	${DISTNAME:S/-2-src/.2/}
PKGREVISION=	2
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
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	XERCESCROOT=${LOCALBASE:Q}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
