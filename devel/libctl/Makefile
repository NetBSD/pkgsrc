# $NetBSD: Makefile,v 1.5 2001/02/06 03:16:57 fredb Exp $

DISTNAME=	libctl-1.3
CATEGORIES=	devel
MASTER_SITES=	http://superjdj.mit.edu/libctl/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/

DEPENDS+=	guile-[0-9]*:../../lang/guile
BUILD_DEPENDS+=	${LOCALBASE}/bin/autoreconf:../../devel/autoconf

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libctl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/libctl
	@for f in COPYING COPYRIGHT ChangeLog NEWS README ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/libctl ; done

.include "../../mk/bsd.pkg.mk"
