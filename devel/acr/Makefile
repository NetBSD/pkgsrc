# $NetBSD: Makefile,v 1.19 2020/05/16 09:45:49 rillig Exp $

DISTNAME=		acr-1.9.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=radare/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/radare/acr
COMMENT=		Autoconf replacement
LICENSE=		gnu-gpl-v2

# Only defines the install target
NO_BUILD=		yes

GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

# Had been forgotten in acr-1.7.2, see Makefile.amr.
# https://github.com/radare/acr/issues/22
SUBST_CLASSES+=		ver
SUBST_STAGE.ver=	post-configure
SUBST_FILES.ver=	src/acr-cat src/acr-sh
SUBST_SED.ver=		-e s,@VERSION@,${PKGVERSION_NOREV},
SUBST_SED.ver+=		-e s,@DATADIR@,${PREFIX}/share,

SUBST_CLASSES+=		eqeq
SUBST_STAGE.eqeq=	pre-configure
SUBST_FILES.eqeq=	src/acr-sh
SUBST_SED.eqeq=		-e '2125s, == , = ,'

post-install:
	${RUN} cd ${WRKSRC}; \
	${INSTALL_DATA} configure.acr ${DESTDIR}${PREFIX}/share/examples/acr/

.include "../../mk/bsd.pkg.mk"
