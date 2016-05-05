# $NetBSD: Makefile,v 1.1 2016/05/05 03:57:26 agc Exp $

DISTNAME=	duktape-1.5.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://duktape.org/
COMMENT=	Embeddable Javascript engine library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LIBTOOL=	yes

do-configure:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
