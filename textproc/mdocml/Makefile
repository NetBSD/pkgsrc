# $NetBSD: Makefile,v 1.17 2010/01/02 13:44:20 joerg Exp $

DISTNAME=		mdocml-1.9.14
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		mdoc macro compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

INSTALLATION_DIRS=	share/examples/mandoc

.include "../../mk/bsd.pkg.mk"
