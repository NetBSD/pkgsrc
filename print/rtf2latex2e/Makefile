# $NetBSD: Makefile,v 1.8 2025/07/04 14:44:40 schmonz Exp $

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

.include "../../mk/bsd.pkg.mk"
