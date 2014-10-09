# $NetBSD: Makefile,v 1.31 2014/10/09 14:06:56 wiz Exp $

DISTNAME=	osh-20100430
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/

MAINTAINER=	jan+nbsd@v6shell.org
HOMEPAGE=	http://v6shell.org/
COMMENT=	Port of the Sixth Edition UNIX shell
LICENSE=	original-bsd

PKG_SHELL=		bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q} BINGRP= MANGRP=

.include "../../mk/bsd.pkg.mk"
