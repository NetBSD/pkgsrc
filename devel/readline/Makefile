# $NetBSD: Makefile,v 1.53 2013/04/17 09:09:57 obache Exp $

DISTNAME=	readline-6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

LDFLAGS.Cygwin+=	-no-undefined

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
