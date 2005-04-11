# $NetBSD: Makefile,v 1.21 2005/04/11 21:45:26 tv Exp $

DISTNAME=	libctl-2.2
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
