# $NetBSD: Makefile,v 1.5 2006/02/19 00:55:46 wiz Exp $
#

DISTNAME=		pine-pgp-filters-1.1
PKGREVISION=		3
CATEGORIES=		security mail
MASTER_SITES=		http://dougbarton.net/FreeBSD/Downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://dougbarton.net/FreeBSD/Downloads/
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
