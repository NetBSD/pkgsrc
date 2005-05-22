# $NetBSD: Makefile,v 1.14 2005/05/22 20:51:45 jlam Exp $

DISTNAME=       autoconf-2.13
PKGNAME=	autoconf213-2.13
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)

USE_TOOLS+=		gm4
TOOLS_DEPMETHOD.gm4=	DEPENDS

CONFLICTS=		autoconf-devel-[0-9]*
CONFLICTS=		autoconf<2.50

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.13/'

USE_MAKEINFO=		YES
INFO_FILES=		autoconf213.info

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
