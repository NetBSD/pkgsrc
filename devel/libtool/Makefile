# $NetBSD: Makefile,v 1.34 2001/10/18 15:20:11 veego Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${PKGPFX}${PKGREV}
SVR4_PKGNAME=	ltool

DEPENDS+=	${PKGPFX:C/-/-base-/}${PKGREV}:../libtool-base
DEPENDS+=	${PKGPFX:C/-/-info-/}${PKGREV}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
