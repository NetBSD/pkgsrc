# $NetBSD: Makefile,v 1.43 2004/10/14 19:04:56 tv Exp $

.include "Makefile.common"

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../libtool-base
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../libtool-info

# There is no libltdl dependency here; this is deliberate, so that libltdl
# can be updated independently of the rest of libtool.

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-patch:

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
