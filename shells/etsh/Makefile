# $NetBSD: Makefile,v 1.3 2022/12/06 19:27:30 vins Exp $

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

MAKE_FLAGS+=	PREFIX=${PREFIX}
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
