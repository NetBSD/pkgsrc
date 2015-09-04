# $NetBSD: Makefile,v 1.2 2015/09/04 13:46:37 wiz Exp $

DISTNAME=	miller-2.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_PROJECT=	miller
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

BUILDLINK_TRANSFORM+=	rm:-Werror
MAKE_JOBS_SAFE=		no
MAKE_FLAGS+=		INSTALLDIR=${DESTDIR}${PREFIX}/bin
INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
