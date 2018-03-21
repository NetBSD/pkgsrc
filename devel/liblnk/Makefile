# $NetBSD: Makefile,v 1.2 2018/03/21 13:30:08 wiz Exp $

DISTNAME=	liblnk-alpha-20171101
PKGNAME=	${DISTNAME:S/-alpha//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/liblnk/wiki
COMMENT=	Library to handle Windows .lnk shortcuts
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	bash
REPLACE_BASH+=	tests/*.sh

.include "../../mk/bsd.pkg.mk"
