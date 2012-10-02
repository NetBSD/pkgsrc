# $NetBSD: Makefile,v 1.11 2012/10/02 21:25:23 asau Exp $
#

DISTNAME=		ocaml-mysql-1.1.1
CATEGORIES=		databases
MASTER_SITES=		http://forge.ocamlcore.org/frs/download.php/870/

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://ocaml-mysql.forge.ocamlcore.org/
COMMENT=		Ocaml library for MySQL database access
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ocaml-mysql
INSTALLATION_DIRS=	${DOCDIR}

BUILD_TARGET=	all htdoc
PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
BUILD_TARGET+=	opt
PLIST.opt=	yes
.endif

post-install:
	cd ${WRKSRC}/doc/mysql/html && ${INSTALL_DATA} *.html ${DESTDIR}${DOCDIR}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
