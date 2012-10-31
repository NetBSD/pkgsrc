# $NetBSD: Makefile,v 1.29 2012/10/31 11:17:11 asau Exp $

DISTNAME=	libctl-2.2
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	share/doc/libctl
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${DESTDIR}${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
