# $NetBSD: Makefile,v 1.18 2013/10/10 14:42:31 ryoon Exp $
#

DISTNAME=		amtterm-1.3
PKGREVISION=		13
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kraxel.org/releases/amtterm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		Active Management Technology (AMT) tools
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite

USE_TOOLS+=		gmake pkg-config perl:run

MAKE_FILE=		GNUmakefile
MAKE_FLAGS+=		prefix=${PREFIX}

REPLACE_PERL+=		amttool

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
