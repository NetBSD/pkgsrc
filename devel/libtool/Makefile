# $NetBSD: Makefile,v 1.45 2009/12/15 17:35:36 joerg Exp $

META_PACKAGE=	# empty

.include "Makefile.common"

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../../devel/libtool-base
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../../devel/libtool-info

# There is no libltdl dependency here; this is deliberate, so that libltdl
# can be updated independently of the rest of libtool.

COMMENT=	Generic shared library support script

.include "../../mk/bsd.pkg.mk"
