# $NetBSD: Makefile,v 1.6 2012/10/31 11:17:34 asau Exp $
#

DISTNAME=	omake-${VERSION}-0.rc1
PKGNAME=	omake-${VERSION}.0rc1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://omake.metaprl.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://omake.metaprl.org/index.html
COMMENT=	Build system designed for scalability and portability
LICENSE=	gnu-gpl-v2 AND mit AND gnu-lgpl-v2.1

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/omake-${VERSION}

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

VERSION=	0.9.8.6

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
