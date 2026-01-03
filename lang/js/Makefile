# $NetBSD: Makefile,v 1.12 2026/01/03 10:37:18 wiz Exp $

DISTNAME=		js-0.2.5
PKGREVISION=		2
CATEGORIES=		lang
#MASTER_SITES=		http://www.njs-javascript.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.njs-javascript.org/
COMMENT=		JavaScript virtual machine
LICENSE=		gnu-lgpl-v2

CONFLICTS=		spidermonkey-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

CFLAGS+=		-Wno-builtin-declaration-mismatch
CFLAGS+=		-Wno-implicit-function-declaration

.include "../../mk/bsd.pkg.mk"
