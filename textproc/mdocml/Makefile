# $NetBSD: Makefile,v 1.3 2009/03/02 09:39:53 wiz Exp $

DISTNAME=		mdocml-1.3.13
CATEGORIES=		devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		mdoc macro compiler

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		mdoclint-[0-9]*

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS=	man/man3

.include "../../mk/bsd.pkg.mk"
