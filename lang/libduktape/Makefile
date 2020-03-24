# $NetBSD: Makefile,v 1.5 2020/03/24 13:49:11 nia Exp $

DISTNAME=	duktape-2.5.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://duktape.org/
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
