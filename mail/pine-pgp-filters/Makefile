# $NetBSD: Makefile,v 1.15 2020/09/07 06:38:27 wiz Exp $

DISTNAME=		pine-pgp-filters-1.8
CATEGORIES=		security mail
MASTER_SITES=		https://dougbarton.us/PGP/ppf/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://dougbarton.us/PGP/ppf/
COMMENT=		Filters to integrate Pine with gnupg or pgp

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

DOCDIR=		${PREFIX}/share/doc/pine-pgp-filters
DOCFILES=	BUGS CHANGES INSTALL LICENSE README

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

INSTALLATION_DIRS=	${DOCDIR}

post-build:
.for f in ${DOCFILES}
	${SED} 's:/usr/local:${PREFIX}:g' ${WRKSRC}/${f} > ${WRKSRC}/${f}.gen
.endfor

pre-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.gen ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
