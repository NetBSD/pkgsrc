# $NetBSD: Makefile,v 1.33 2022/05/24 18:59:20 jaapb Exp $
#

VERSION=	1.2.4
GITHUB_PROJECT=	ocaml-mysql
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=ygrek/}

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		https://github.com/ygrek/ocaml-mysql
COMMENT=		Ocaml library for MySQL database access
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ocaml-mysql
INSTALLATION_DIRS=	${DOCDIR}
MAKE_JOBS_SAFE=		no
# parallelism here leads to errors and there's not much that can be done
# in parallel anyway
OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"

BUILD_TARGET=	all htdoc
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

post-install:
	cd ${WRKSRC}/doc/mysql/html && ${INSTALL_DATA} *.html ${DESTDIR}${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
