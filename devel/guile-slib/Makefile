# $NetBSD: Makefile,v 1.20 2004/10/03 00:13:28 tv Exp $

DISTNAME=	guile-slib-2.4.2
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB installation for guile Scheme interpreter

DEPENDS+=	slib>=2.4.2:../../devel/slib

USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

PLIST_SUBST+=	GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/${GUILE14_SUBDIR}/share/guile/slib
	cd ${PREFIX}/${GUILE14_SUBDIR}/share/guile/slib; \
		${PREFIX}/${GUILE14_SUBDIR}/bin/guile -q -s \
			${FILESDIR}/gencat.scm

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
