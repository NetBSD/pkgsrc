# $NetBSD: Makefile,v 1.12 2016/08/07 23:20:46 mef Exp $

DISTNAME=		acr-0.10.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=radare/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/radare/acr
COMMENT=		Autoconf replacement
LICENSE=		gnu-gpl-v2

# Only defined the install target
NO_BUILD=		yes

GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

post-install:
	(cd ${WRKSRC}; \
	${INSTALL_DATA} configure.acr ${DESTDIR}${PREFIX}/share/examples/acr/; \
	)
.include "../../mk/bsd.pkg.mk"
