# $NetBSD: Makefile,v 1.1.1.1 2011/05/13 13:24:01 obache Exp $
#

DISTNAME=		amtterm-1.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kraxel.org/releases/amtterm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		Active Management Technology (AMT) tools
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config perl:run

MAKE_FILE=		GNUmakefile
MAKE_FLAGS+=		prefix=${PREFIX}

REPLACE_PERL+=		amttool

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
