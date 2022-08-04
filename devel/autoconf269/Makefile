# $NetBSD: Makefile,v 1.1 2022/08/04 12:31:41 jperkin Exp $

DISTNAME=	autoconf-2.69
PKGNAME=	autoconf269-2.69
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gm4:run makeinfo perl:run

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.69/'

INSTALL_DIRS=	bin lib

.include "../../mk/bsd.pkg.mk"
