# $NetBSD: Makefile,v 1.5 2001/10/03 09:08:37 jlam Exp $

DISTNAME=	guile-slib-2.4.2
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB installation for guile Scheme interpreter

DEPENDS+=	guile>=1.3.2:../../lang/guile
DEPENDS+=	slib-${PKGVERSION}:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ../slib ${PREFIX}/share/guile/slib
	cd ${PREFIX}/share/guile/slib; \
		${LOCALBASE}/bin/guile -q -s ${FILESDIR}/gencat.scm

.include "../../mk/bsd.pkg.mk"
