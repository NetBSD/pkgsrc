# $NetBSD: Makefile,v 1.123 2026/09/24 13:26:14 wiz Exp $
#
# for major version updates, don't forget adding new links in
# mk/tools/automake.mk

DISTNAME=	automake-1.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
MASTER_SITES+=	ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator
LICENSE=	gnu-gpl-v2

AUTOCONF_REQD+=	2.62
USE_TOOLS+=	autoconf gm4:run perl:run

PLIST_SUBST+=		PKG_DIR_VERSION=1.19
GNU_CONFIGURE=		yes
INFO_FILES=		yes

# doesn't work because pkgsrc hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
