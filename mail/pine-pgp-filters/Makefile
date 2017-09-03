# $NetBSD: Makefile,v 1.13 2017/09/03 08:53:11 wiz Exp $
#

DISTNAME=		pine-pgp-filters-1.6
CATEGORIES=		security mail
PKGREVISION=		1
#MASTER_SITES=		https://dougbarton.us/PGP/scripts/ppf/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://dougbarton.us/PGP/scripts/ppf/
COMMENT=		Filters to integrate Pine with gnupg or pgp

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

DOCDIR=			 ${PREFIX}/share/doc/pine-pgp-filters
DOCFILES=		BUGS CHANGES INSTALL LICENSE README

DEPENDS+=	gnupg>=1.4.9:../../security/gnupg

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
