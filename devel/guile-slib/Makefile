# $NetBSD: Makefile,v 1.14 2003/05/05 00:03:35 seb Exp $

DISTNAME=	guile-slib-2.4.2
PKGREVISION=	1
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

PLIST_SUBST+=	GUILE14_SUBDIR=${GUILE14_SUBDIR}

do-install:
	${LN} -sf ${PREFIX}/share/slib ${GUILE14_PREFIX}/share/guile/slib
	cd ${GUILE14_PREFIX}/share/guile/slib; \
		${GUILE14} -q -s ${FILESDIR}/gencat.scm

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
