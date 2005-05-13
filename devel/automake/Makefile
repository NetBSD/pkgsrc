# $NetBSD: Makefile,v 1.62 2005/05/13 16:54:12 jlam Exp $
#

DISTNAME=	automake-1.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/} \
		ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.58:../../devel/autoconf

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PLIST_SUBST+=		PKG_DIR_VERSION=1.9
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none
EVAL_PREFIX+=		M4DIR=m4
TOOLS_M4=		${M4DIR}/bin/${GNU_PROGRAM_PREFIX}m4

INFO_FILES=		automake.info

PERL5_REQD+=		5.5

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
