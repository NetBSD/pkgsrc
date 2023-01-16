# $NetBSD: Makefile,v 1.4 2023/01/16 03:52:32 dholland Exp $

DISTNAME=	owl-v0.2
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
