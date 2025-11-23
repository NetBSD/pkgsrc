# $NetBSD: Makefile,v 1.3 2025/11/23 08:10:17 wiz Exp $

DISTNAME=	autosetup-0.6.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msteveb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msteveb.github.io/autosetup/
COMMENT=	Better, faster autoconf replacement
LICENSE=	2-clause-bsd

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

do-install:
	cd ${WRKSRC} && ./autosetup --sysinstall=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
