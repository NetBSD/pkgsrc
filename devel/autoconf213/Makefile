# $NetBSD: Makefile,v 1.37 2022/06/28 11:31:39 wiz Exp $

DISTNAME=	autoconf-2.13
PKGNAME=	autoconf213-2.13
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gm4:run makeinfo perl:run

CONFLICTS=		autoconf-devel-[0-9]*
CONFLICTS+=		autoconf<2.50

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.13/'
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
