# $NetBSD: Makefile,v 1.28 2018/11/12 16:10:17 jaapb Exp $
#

VERSION=	1.2.0
GITHUB_PROJECT=	ocaml-mysql
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=		7
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=ygrek/}

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://ocaml-mysql.forge.ocamlcore.org/
COMMENT=		Ocaml library for MySQL database access
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ocaml-mysql
INSTALLATION_DIRS=	${DOCDIR}

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

BUILD_TARGET=	all htdoc
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

post-install:
	cd ${WRKSRC}/doc/mysql/html && ${INSTALL_DATA} *.html ${DESTDIR}${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
