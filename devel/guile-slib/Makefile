# $NetBSD: Makefile,v 1.27 2005/10/16 23:42:16 gdt Exp $

DISTNAME=	guile-slib-2.4.2
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.6

DEPENDS+=	slib>=2.4.2:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile

do-build:

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/share/guile/slib
	cd ${PREFIX}/share/guile/slib; \
		guile -q -s ${FILESDIR}/gencat.scm

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
