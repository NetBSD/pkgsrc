# $NetBSD: Makefile,v 1.13 2003/01/10 11:46:49 wiz Exp $

DISTNAME=	libctl-1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${PREFIX}/share/doc/libctl/

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
