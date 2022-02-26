# $NetBSD: Makefile,v 1.22 2022/02/26 16:26:38 fcambus Exp $

DISTNAME=		acr-2.0.0
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
