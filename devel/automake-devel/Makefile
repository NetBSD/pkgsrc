# $NetBSD: Makefile,v 1.3 2002/08/28 08:49:44 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.53:../../devel/autoconf-devel

PLIST_SUBST+=		PKG_DIR_VERSION=1.6
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none
M4=			${PREFIX}/bin/gm4

MAKEINFOFLAGS=		--no-split
MAKE_ENV+=		MAKEINFOFLAGS="${MAKEINFOFLAGS}"

INFO_FILES=		automake.info

PERL5_REQD=		5.5
TEXINFO_REQD=		4.0
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
