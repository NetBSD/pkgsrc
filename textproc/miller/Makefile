# $NetBSD: Makefile,v 1.1 2015/08/28 09:27:10 wiz Exp $

DISTNAME=	miller-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_PROJECT=	miller
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

BUILDLINK_TRANSFORM+=	rm:-Werror
MAKE_JOBS_SAFE=		no
MAKE_FLAGS+=		INSTALLDIR=${DESTDIR}${PREFIX}/bin
INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
