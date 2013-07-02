# $NetBSD: Makefile,v 1.95 2013/07/02 06:37:00 wiz Exp $

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
