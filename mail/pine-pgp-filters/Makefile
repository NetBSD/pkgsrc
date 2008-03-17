# $NetBSD: Makefile,v 1.7 2008/03/17 11:53:37 obache Exp $
#

DISTNAME=		pine-pgp-filters-1.1
PKGREVISION=		3
CATEGORIES=		security mail
MASTER_SITES=		http://dougbarton.us/PGP/scripts/ppf/Old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dougbarton.us/PGP/scripts/ppf/
COMMENT=		Filters to integrate Pine with gnupg or pgp

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

DOCDIR=			 ${PREFIX}/share/doc/pine-pgp-filters
DOCFILES=		BUGS CHANGES INSTALL LICENSE README

do-build:
.for f in ${DOCFILES}
	${SED} 's:/usr/local:${PREFIX}:g' ${WRKSRC}/${f} > ${WRKSRC}/${f}.gen
.endfor

post-install:
	${RM} ${PREFIX}/libexec/ppf_*.orig
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.gen ${DOCDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
