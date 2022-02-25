# $NetBSD: Makefile,v 1.9 2022/02/25 20:50:07 fcambus Exp $

DISTNAME=	duktape-2.7.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://duktape.org/
COMMENT=	Embeddable Javascript engine library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LIBTOOL=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	duktape.pc
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	COMPILER_RPATH_FLAG

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/duktape.pc ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
