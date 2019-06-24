# $NetBSD: Makefile,v 1.4 2019/06/24 10:59:42 nia Exp $

DISTNAME=	duktape-2.3.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://duktape.org/
COMMENT=	Embeddable Javascript engine library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LIBTOOL=	yes

do-configure:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
