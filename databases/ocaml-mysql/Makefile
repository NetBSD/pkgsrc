# $NetBSD: Makefile,v 1.3 2008/01/18 05:06:28 tnn Exp $
#

DISTNAME=		ocaml-mysql-1.0.4
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://raevnos.pennmush.org/code/ocaml-mysql/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://raevnos.pennmush.org/code/ocaml-mysql/
COMMENT=		Ocaml library for MySQL database access

BUILD_DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ocaml-mysql
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${DOCDIR}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
