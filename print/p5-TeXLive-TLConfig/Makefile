# $NetBSD: Makefile,v 1.2 2024/11/16 12:06:24 wiz Exp $

VERSION=	0.66420
DISTNAME=	TLConfig
PKGNAME=	p5-TeXLive-${DISTNAME}-${VERSION}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://tug.ctan.org/systems/texlive/tlnet/tlpkg/TeXLive/
EXTRACT_SUFX=	.pm
DIST_SUBDIR=	TLConfig-${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tug.ctan.org/systems/texlive/tlnet/tlpkg/TeXLive/
COMMENT=	TeXLive Install Utilities
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/TeXLive
	cd ${WRKSRC}; ${INSTALL_DATA} TLConfig.pm ${DESTDIR}${PERL5_INSTALLVENDORLIB}/TeXLive

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
