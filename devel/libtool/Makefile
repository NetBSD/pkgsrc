# $NetBSD: Makefile,v 1.33 2001/02/27 08:20:24 skrll Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${PKGPFX}${PKGREV}

DEPENDS+=	${PKGPFX:C/-/-base-/}${PKGREV}:../libtool-base
DEPENDS+=	${PKGPFX:C/-/-info-/}${PKGREV}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
