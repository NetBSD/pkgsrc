# $NetBSD: Makefile,v 1.35.2.1 2002/06/23 18:44:29 jlam Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${PKGPFX}
SVR4_PKGNAME=	ltool

DEPENDS+=	${PKGPFX:S/-/-base-/}${PKGREVISION:C/[0-9]*/nb/}${PKGREVISION}:../libtool-base
DEPENDS+=	${PKGPFX:S/-/-info-/}${PKGREVISION:C/[0-9]*/nb/}${PKGREVISION}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
