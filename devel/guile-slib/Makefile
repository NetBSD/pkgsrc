# $NetBSD: Makefile,v 1.10 2003/01/16 02:26:10 uebayasi Exp $

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

INFO_FILES=	slib.info

GUILE14_PREFIX=	guile/1.4
PLIST_SUBST+=	GUILE14_PREFIX=${GUILE14_PREFIX}

do-install:
	${LN} -sf ${PREFIX}/share/slib ${BUILDLINK_PREFIX.guile14}/${GUILE14_PREFIX}/share/guile/slib
	cd ${BUILDLINK_PREFIX.guile14}/${GUILE14_PREFIX}/share/guile/slib; \
		${BUILDLINK_PREFIX.guile14}/${GUILE14_PREFIX}/bin/guile -q -s ${FILESDIR}/gencat.scm

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
