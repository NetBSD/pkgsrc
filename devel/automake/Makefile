# $NetBSD: Makefile,v 1.42 2003/12/06 18:28:13 wiz Exp $
#

DISTNAME=	automake-1.7.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.54:../../devel/autoconf

PLIST_SUBST+=		PKG_DIR_VERSION=1.7
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none
M4=			${PREFIX}/bin/gm4

MAKEINFOFLAGS=		--no-split
MAKE_ENV+=		MAKEINFOFLAGS="${MAKEINFOFLAGS}"

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		automake.info

PERL5_REQD=		5.5

TEST_TARGET=		check

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
