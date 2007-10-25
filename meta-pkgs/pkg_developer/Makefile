# $NetBSD: Makefile,v 1.3 2007/10/25 22:00:56 jlam Exp $
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

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
