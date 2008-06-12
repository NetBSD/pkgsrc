# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:35 joerg Exp $
#

DISTNAME=		pine-pgp-filters-1.1
PKGREVISION=		3
CATEGORIES=		security mail
MASTER_SITES=		http://dougbarton.us/PGP/scripts/ppf/Old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dougbarton.us/PGP/scripts/ppf/
COMMENT=		Filters to integrate Pine with gnupg or pgp

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

DOCDIR=			 ${PREFIX}/share/doc/pine-pgp-filters
DOCFILES=		BUGS CHANGES INSTALL LICENSE README

INSTALLATION_DIRS=	${DOCDIR}

do-build:
.for f in ${DOCFILES}
	${SED} 's:/usr/local:${PREFIX}:g' ${WRKSRC}/${f} > ${WRKSRC}/${f}.gen
.endfor

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/ppf_*.orig
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.gen ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
