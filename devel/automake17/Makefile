# $NetBSD: Makefile,v 1.4 2004/02/11 00:56:51 jlam Exp $
#

DISTNAME=	automake-1.7.9
PKGNAME=	automake17-1.7.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator (latest 1.7 version)

DEPENDS=	autoconf>=2.54:../../devel/autoconf

CONFLICTS=	automake-1.7*

PLIST_SUBST+=		PKG_DIR_VERSION=1.7
USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none
M4=			${PREFIX}/bin/gm4

MAKEINFOFLAGS=		--no-split
MAKE_ENV+=		MAKEINFOFLAGS="${MAKEINFOFLAGS}"

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		automake17.info

PERL5_REQD+=		5.5

TEST_TARGET=		check

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
