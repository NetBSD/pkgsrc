# $NetBSD: Makefile,v 1.20 2020/06/12 17:23:51 rillig Exp $

DISTNAME=		acr-1.9.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=radare/}
EXTRACT_SUFX=		.zip

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
