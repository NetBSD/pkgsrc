# $NetBSD: Makefile,v 1.4 2009/03/03 15:13:13 joerg Exp $

DISTNAME=		mdocml-1.3.15
CATEGORIES=		devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		mdoc macro compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
CONFLICTS=		mdoclint-[0-9]*

.include "../../mk/bsd.pkg.mk"
