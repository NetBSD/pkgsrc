# $NetBSD: Makefile,v 1.21 2021/01/25 07:58:51 fcambus Exp $

DISTNAME=		acr-1.9.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=radare/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/radare/acr
COMMENT=		Autoconf replacement
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes	# not quite, but close enough
AUTO_MKDIRS=		yes

post-install:
	${RUN} cd ${WRKSRC}; \
	${INSTALL_DATA} configure.acr ${DESTDIR}${PREFIX}/share/examples/acr/

.include "../../mk/bsd.pkg.mk"
