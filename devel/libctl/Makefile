# $NetBSD: Makefile,v 1.25 2009/06/30 00:07:12 joerg Exp $

DISTNAME=	libctl-2.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
