# $NetBSD: Makefile,v 1.15 2003/06/02 01:20:41 jschauma Exp $

DISTNAME=	libctl-2.2
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
