# $NetBSD: Makefile,v 1.67 2005/07/16 19:10:38 jlam Exp $
#

DISTNAME=	automake-1.9.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/} \
		ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.58:../../devel/autoconf

USE_TOOLS+=	gm4:run perl:run

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PLIST_SUBST+=		PKG_DIR_VERSION=1.9
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none

INFO_FILES=		automake.info

PERL5_REQD+=		5.5

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
