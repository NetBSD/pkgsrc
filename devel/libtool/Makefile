# $NetBSD: Makefile,v 1.40 2004/02/05 20:14:06 skrll Exp $
#

.include "Makefile.common"

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}${PKGREVISION:C/[0-9]*/nb/}${PKGREVISION}:../libtool-base
DEPENDS+=	${DISTNAME:S/-/-info-/}${PKGREVISION:C/[0-9]*/nb/}${PKGREVISION}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-patch:

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
