# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 21:34:05 jtb Exp $

DISTNAME=	libctl-1.2
CATEGORIES=	devel
MASTER_SITES=	http://superjdj.mit.edu/libctl/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/

DEPENDS+=	guile>=1.0.0:../../lang/guile

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
MAKE_ENV+="VERSION=1:2:0"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	@(for f in ${WRKSRC}/doc/* ; do				\
	${INSTALL_DATA} $$f ${PREFIX}/share/doc/libctl ;	\
	done)
	@for f in COPYING COPYRIGHT ChangeLog NEWS README ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/libctl ; done

.include "../../mk/bsd.pkg.mk"
