# $NetBSD: Makefile,v 1.9 2003/01/07 03:56:22 uebayasi Exp $

DISTNAME=	guile-slib-2.4.2
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB installation for guile Scheme interpreter

DEPENDS+=	slib>=2.4.2:../../devel/slib

USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ../slib ${PREFIX}/share/guile/slib
	cd ${PREFIX}/share/guile/slib; \
		${LOCALBASE}/bin/guile -q -s ${FILESDIR}/gencat.scm

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
