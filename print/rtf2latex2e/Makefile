# $NetBSD: Makefile,v 1.9 2026/08/04 20:29:13 wiz Exp $

DISTNAME=	rtf2latex2e-2-2-3
PKGNAME=	${DISTNAME:S/-/./g:S/./-/}
CATEGORIES=	print textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rtf2latex2e/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/rtf2latex2e/
COMMENT=	RTF to LaTeX2e converter
LICENSE=	gnu-gpl-v2

MAKE_ENV+=	prefix=${PREFIX}
MAKE_ENV+=	mandir=${PREFIX}/${PKGMANDIR}
TEST_TARGET=	test

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	${PREFIX}/share/doc/${PKGBASE}/html

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
