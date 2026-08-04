# $NetBSD: Makefile,v 1.37 2026/08/04 20:28:48 wiz Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://download.oracle.com/berkeley-db/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oracle.com/database/berkeley-db.html
COMMENT=	Sleepycat Software's Berkeley DB version 2
LICENSE=	sleepycat-license # minus ASM stanza

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db2_,
CONFIGURE_ARGS+=	--enable-compat185

INSTALLATION_DIRS=	bin include/db2 lib share/doc/db2

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/doc/db2

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
