# $NetBSD: Makefile,v 1.4 2007/12/19 12:27:30 rillig Exp $
#

DISTNAME=	pkg_developer-1.1
CATEGORIES=	meta-pkgs pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Meta-package for pkgsrc package development

DEPENDS+=	checkperms>=1.0:../../sysutils/checkperms
DEPENDS+=	createbuildlink>=3.13:../../pkgtools/createbuildlink
DEPENDS+=	digest>=20060302:../../pkgtools/digest
DEPENDS+=	pkg_chk>=1.77:../../pkgtools/pkg_chk
DEPENDS+=	pkg_tarup>=1.6.5:../../pkgtools/pkg_tarup
DEPENDS+=	pkgdiff>=0.119:../../pkgtools/pkgdiff
DEPENDS+=	pkglint>=4.67:../../pkgtools/pkglint
DEPENDS+=	revbump>=1.8:../../pkgtools/revbump
DEPENDS+=	url2pkg>=1.34:../../pkgtools/url2pkg
DEPENDS+=	verifypc>=1.3:../../pkgtools/verifypc

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
