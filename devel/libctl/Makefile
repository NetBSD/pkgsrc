# $NetBSD: Makefile,v 1.7 2001/02/24 13:42:06 jtb Exp $

DISTNAME=	libctl-1.4
CATEGORIES=	devel
MASTER_SITES=	http://superjdj.mit.edu/libctl/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

DEPENDS+=	guile>=1.4:../../lang/guile

GNU_CONFIGURE=	#defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	@for f in ${WRKSRC}/doc/*; do					\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/libctl/";		\
	${ECHO} $$i; $$i;						\
	done
	@for f in COPYING COPYRIGHT ChangeLog NEWS README ; do		\
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/libctl/";	\
	${ECHO} $$i; $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
