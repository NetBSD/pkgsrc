# $NetBSD: Makefile,v 1.32 2001/02/16 14:38:40 wiz Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${DISTNAME}${PKGREV}

COMMENT=	Generic shared library support script

DEPENDS+=	${DISTNAME:C/-/-base-/}${PKGREV}:../libtool-base
DEPENDS+=	${DISTNAME:C/-/-info-/}${PKGREV}:../libtool-info

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
