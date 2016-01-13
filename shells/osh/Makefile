# $NetBSD: Makefile,v 1.32 2016/01/13 13:14:21 nros Exp $

DISTNAME=	osh-20160108
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/

MAINTAINER=	jan+nbsd@v6shell.org
HOMEPAGE=	http://v6shell.org/
COMMENT=	Port of the Sixth Edition UNIX shell
LICENSE=	original-bsd

PKG_SHELL=	bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall install-doc

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q} BINGRP= MANGRP=

.include "../../mk/bsd.pkg.mk"
