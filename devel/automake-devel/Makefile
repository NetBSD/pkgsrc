# $NetBSD: Makefile,v 1.5 2002/09/28 10:22:55 wiz Exp $
#

DISTNAME=	automake-1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.54:../../devel/autoconf-devel

PLIST_SUBST+=		PKG_DIR_VERSION=1.7
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none
M4=			${PREFIX}/bin/gm4

MAKEINFOFLAGS=		--no-split
MAKE_ENV+=		MAKEINFOFLAGS="${MAKEINFOFLAGS}"

INFO_FILES=		automake.info

PERL5_REQD=		5.5
TEXINFO_REQD=		4.1
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
