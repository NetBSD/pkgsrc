# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:40 wiz Exp $

DISTNAME=	automake-1.4-p6
PKGNAME=	automake14-1.4.6
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator (old version)
LICENSE=	gnu-gpl-v2

DEPENDS+=	autoconf213>=2.13:../../devel/autoconf213

CONFLICTS=	automake<1.6

GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none

USE_TOOLS+=	makeinfo perl:run
INFO_FILES=	yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
