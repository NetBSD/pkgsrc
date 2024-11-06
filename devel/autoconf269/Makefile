# $NetBSD: Makefile,v 1.2 2024/11/06 15:34:47 taca Exp $

DISTNAME=	autoconf-2.69
PKGNAME=	autoconf269-2.69
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gm4:run makeinfo perl:run

USE_LANGUAGES=	# empty
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.69/'
CONFIGURE_ARGS+=	--without-lispdir
CONFIGURE_ENV+=		ac_cv_prog_TEST_EMACS=no

INSTALL_DIRS=	bin lib

.include "../../mk/bsd.pkg.mk"
