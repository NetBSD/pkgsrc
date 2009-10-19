# $NetBSD: Makefile,v 1.13 2009/10/19 22:38:33 joerg Exp $

DISTNAME=		mdocml-1.9.8
CATEGORIES=		textproc devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		mdoc macro compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

.include "../../mk/bsd.pkg.mk"
