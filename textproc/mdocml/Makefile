# $NetBSD: Makefile,v 1.27 2012/01/04 15:31:31 dholland Exp $

DISTNAME=		mdocml-1.12.0
CATEGORIES=		textproc devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		Man page tool (mdoc macro compiler)
LICENSE=		2-clause-bsd # not exactly, but near enough

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
