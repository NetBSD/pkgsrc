# $NetBSD: Makefile,v 1.1 2022/07/04 08:31:43 pin Exp $

DISTNAME=	etsh-5.4.0
CATEGORIES=	shells
MASTER_SITES=	https://etsh.nl/src/etsh_5.4.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://etsh.nl/
COMMENT=	Enhanced port of Thompson shell from V6 UNIX
LICENSE=	original-bsd AND modified-bsd AND 2-clause-bsd

HAS_CONFIGURE=	yes

PKG_SHELL=	bin/etsh

EXPDIR:=	${PREFIX}/share/examples/etsh
DOCDIR:=	${PREFIX}/share/doc/etsh

MAKEFLAGS+=	PREFIX=${PREFIX}
MAKEFLAGS+=	DESTDOCDIR=${DESTDIR}${DOCDIR}
MAKEFLAGS+=	DESTEXPDIR=${DESTDIR}${EXPDIR}
MAKEFLAGS+=	MANGRP:='' BINGRP:=''

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	libexec.etsh/etshdir
SUBST_FILES.paths+=	libexec.etsh/history
SUBST_FILES.paths+=	libexec.etsh/pev
SUBST_SED.paths=	-e 's|/usr/bin/env |${PREFIX}/bin/|'

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} exp

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-exp \
	install-doc

.include "../../mk/bsd.pkg.mk"
