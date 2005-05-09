# $NetBSD: Makefile,v 1.5 2005/05/09 20:29:26 kristerw Exp $

DISTNAME=	guile-slib-2.4.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB installation for guile 1.4 Scheme interpreter

DEPENDS+=	slib>=2.4.2:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

PLIST_SUBST+=	GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}

do-build:

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/${GUILE14_SUBDIR}/share/guile/slib
	cd ${PREFIX}/${GUILE14_SUBDIR}/share/guile/slib; \
		${PREFIX}/${GUILE14_SUBDIR}/bin/guile -q -s \
			${FILESDIR}/gencat.scm

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
