# $NetBSD: Makefile,v 1.2 2022/04/23 23:27:55 tnn Exp $

DISTNAME=	owl-v0.2
PKGNAME=	${DISTNAME:S/owl-v/owl-lisp-/}
CATEGORIES=	lang
MASTER_SITES=	https://gitlab.com/owl-lisp/owl/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://haltp.org/n/owl
COMMENT=	Purely functional dialect of Scheme
LICENSE=	mit

INSTALL_MAKE_FLAGS=	DESTDIR=${DESTDIR}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=/${PKGMANDIR}
MANCOMPRESSED=		yes

.include "../../mk/bsd.pkg.mk"
