# $NetBSD: Makefile,v 1.1.1.1 2000/02/23 20:36:47 jlam Exp $

DISTNAME=	guile-slib-2c7
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html

DEPENDS+=	guile-1.3.*:../../lang/guile
DEPENDS+=	slib-2c7:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ../slib ${PREFIX}/share/guile/slib
	cd ${PREFIX}/share/guile/slib; \
		${LOCALBASE}/bin/guile -q -s ${FILESDIR}/gencat.scm

.include "../../mk/bsd.pkg.mk"
