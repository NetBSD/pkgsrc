# $NetBSD: Makefile,v 1.42 2004/05/26 13:51:07 tron Exp $

.include "Makefile.common"

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../libtool-base
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-patch:

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
