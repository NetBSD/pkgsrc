# $NetBSD: Makefile,v 1.46 2013/05/09 18:26:33 wiz Exp $

META_PACKAGE=	# empty

.include "Makefile.common"
PKGREVISION=	1

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../../devel/libtool-base
DEPENDS+=	${DISTNAME:S/-/-fortran-/}{,nb[0-9]*}:../../devel/libtool-fortran
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../../devel/libtool-info

# There is no libltdl dependency here; this is deliberate, so that libltdl
# can be updated independently of the rest of libtool.

COMMENT=	Generic shared library support script

.include "../../mk/bsd.pkg.mk"
