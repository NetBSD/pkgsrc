# $NetBSD: Makefile,v 1.26 2015/01/24 01:10:43 mef Exp $
#

DISTNAME=	chktex-1.6.4
CATEGORIES=	print
MASTER_SITES=	http://baruch.ev-en.org/proj/chktex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://baruch.ev-en.org/proj/chktex/
COMMENT=	LaTeX semantic checker
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
BUILD_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	lynx-[0-9]*:../../www/lynx

EGDIR=		${PREFIX}/share/examples/chktex
CONF_FILES=	${EGDIR}/chktexrc ${PKG_SYSCONFDIR}/chktexrc

USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
CONFIGURE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} EGDIR=${EGDIR:Q}

INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.pkg.mk"
