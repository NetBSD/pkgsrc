# $NetBSD: Makefile,v 1.51 2021/05/24 19:50:01 wiz Exp $

META_PACKAGE=	# empty

PKGREVISION= 1
.include "Makefile.common"

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../../devel/libtool-base
DEPENDS+=	${DISTNAME:S/-/-fortran-/}{,nb[0-9]*}:../../devel/libtool-fortran
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../../devel/libtool-info

# There is no libltdl dependency here; this is deliberate, so that libltdl
# can be updated independently of the rest of libtool.

COMMENT=	Generic shared library support script

.include "../../mk/bsd.pkg.mk"
