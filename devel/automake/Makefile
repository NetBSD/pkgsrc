# $NetBSD: Makefile,v 1.96 2013/11/30 09:01:26 wiz Exp $
#
# for major version updates, don't forget adding new links in
# mk/tools/automake.mk

DISTNAME=	automake-1.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/} \
		ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator
LICENSE=	gnu-gpl-v2

DEPENDS+=	autoconf>=2.62:../../devel/autoconf

USE_TOOLS+=	gm4:run perl:run

PLIST_SUBST+=		PKG_DIR_VERSION=1.14
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none
INFO_FILES=		YES
REPLACE_PERL=		lib/tap-driver.pl

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
