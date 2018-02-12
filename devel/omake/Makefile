# $NetBSD: Makefile,v 1.19 2018/02/12 11:03:34 dholland Exp $
#

DISTNAME=	omake-0.10.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-omake/}
GITHUB_TAG=	${PKGNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.camlcity.org/projects/omake.html
COMMENT=	Build system designed for scalability and portability
LICENSE=	gnu-gpl-v2 AND mit AND gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/omake-${DISTNAME}

CONFIGURE_ARGS+=	-prefix=${PREFIX}
BUILD_TARGET=		force-bootstrap
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
