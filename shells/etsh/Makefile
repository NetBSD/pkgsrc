# $NetBSD: Makefile,v 1.5 2022/12/20 08:36:51 vins Exp $

DISTNAME=	etsh-5.4.0
CATEGORIES=	shells
MASTER_SITES=	https://etsh.nl/src/etsh_5.4.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://etsh.nl/
COMMENT=	Enhanced port of Thompson shell from V6 UNIX
LICENSE=	original-bsd AND modified-bsd AND 2-clause-bsd

HAS_CONFIGURE=	yes

PKG_SHELL=	bin/etsh

EXPDIR:=	${PREFIX}/share/examples/etsh
DOCDIR:=	${PREFIX}/share/doc/etsh

REPLACE_INTERPRETER+=	tsh
REPLACE.tsh.old=	.*/bin/env etsh
REPLACE.tsh.new=	${PREFIX}/bin/etsh
REPLACE_FILES.tsh+=	libexec.etsh/etshdir
REPLACE_FILES.tsh+=	libexec.etsh/history
REPLACE_FILES.tsh+=	libexec.etsh/pev

MAKE_ENV+=	CC=${CC:Q}
MAKE_ENV+=	CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	INSTALL=${INSTALL:Q}

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	DESTDOCDIR=${DESTDIR}${DOCDIR}
MAKE_FLAGS+=	DESTEXPDIR=${DESTDIR}${EXPDIR}

INSTALL_ENV+=	MANGRP=''
INSTALL_ENV+=	BINGRP=''

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM:Q} exp

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV}			\
		${MAKE_PROGRAM:Q} install-exp install-doc

.include "../../mk/bsd.pkg.mk"
