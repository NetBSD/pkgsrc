# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:53 jlam Exp $

DISTNAME=	libpathan-1.2-2-src
PKGNAME=	${DISTNAME:S/-2-src/.2/}
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/pathan-1.2r2/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://software.decisionsoft.com/
COMMENT=	Library to parse and evaluate XPath expressions

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-2-src//}
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	XERCESCROOT=${LOCALBASE}
CONFIGURE_ARGS+=	YACC=${LOCALBASE}/bin/bison

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
