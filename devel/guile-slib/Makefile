# $NetBSD: Makefile,v 1.22 2004/12/03 15:51:09 wiz Exp $

DISTNAME=	guile-slib-2.4.2
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.6

DEPENDS+=	slib>=2.4.2:../../devel/slib

USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/share/guile/slib
	cd ${PREFIX}/share/guile/slib; \
		guile -q -s ${FILESDIR}/gencat.scm

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
