# $NetBSD: Makefile,v 1.31 2018/08/22 09:46:31 wiz Exp $

DISTNAME=		amtterm-1.4
PKGREVISION=		7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kraxel.org/releases/amtterm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.kraxel.org/blog/linux/amtterm/
COMMENT=		Active Management Technology (AMT) tools
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite

USE_TOOLS+=		gmake pkg-config perl:run tr

MAKE_FILE=		GNUmakefile
MAKE_FLAGS+=		prefix=${PREFIX}

REPLACE_PERL+=		amttool

.include "options.mk"

post-extract:
	${TR} -d '\r' <${WRKSRC}/RedirectionConstants.h >${WRKDIR}/no-dos
	${MV} ${WRKDIR}/no-dos ${WRKSRC}/RedirectionConstants.h

.include "../../mk/bsd.pkg.mk"
