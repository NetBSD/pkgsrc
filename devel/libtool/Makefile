# $NetBSD: Makefile,v 1.31 2001/02/03 05:34:57 hubertf Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${DISTNAME}${PKGREV}

DEPENDS+=	${DISTNAME:C/-/-base-/}${PKGREV}:../libtool-base
DEPENDS+=	${DISTNAME:C/-/-info-/}${PKGREV}:../libtool-info

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
