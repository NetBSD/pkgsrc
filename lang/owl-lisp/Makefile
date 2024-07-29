# $NetBSD: Makefile,v 1.5 2024/07/29 20:09:07 ktnb Exp $

DISTNAME=	owl-v0.2.1
PKGNAME=	${DISTNAME:S/owl-v/owl-lisp-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITLAB:=owl-lisp/}
GITLAB_PROJECT=	owl
GITLAB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://haltp.org/n/owl
COMMENT=	Purely functional dialect of Scheme
LICENSE=	mit

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALL_MAKE_FLAGS=	DESTDIR=${DESTDIR}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=/${PKGMANDIR}
MANCOMPRESSED=		yes

.include "../../mk/bsd.pkg.mk"
