# $NetBSD: Makefile,v 1.11 2001/07/17 14:35:32 taca Exp $

DISTNAME=	libctl-1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

DEPENDS+=	guile>=1.4:../../lang/guile

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${PREFIX}/share/doc/libctl/

.include "../../mk/bsd.pkg.mk"
