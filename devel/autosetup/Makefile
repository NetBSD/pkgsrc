# $NetBSD: Makefile,v 1.2 2020/01/18 23:30:23 rillig Exp $

DISTNAME=	autosetup-0.6.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msteveb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msteveb.github.com/autosetup/
COMMENT=	Better, faster autoconf replacement
LICENSE=	2-clause-bsd

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

do-install:
	cd ${WRKSRC} && ./autosetup --sysinstall=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
