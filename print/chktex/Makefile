# $NetBSD: Makefile,v 1.16 2005/12/05 20:50:52 rillig Exp $
#

DISTNAME=	chktex-1.6.3
CATEGORIES=	print
MASTER_SITES=	http://baruch.ev-en.org/proj/chktex/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://baruch.ev-en.org/proj/chktex/
COMMENT=	LaTeX semantic checker

DEPENDS+=	lynx-[0-9]*:../../www/lynx

USE_PKGINSTALL=yes
EGDIR=      ${PREFIX}/share/examples/chktex
CONF_FILES=   ${EGDIR}/chktexrc ${PKG_SYSCONFDIR}/chktexrc

USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
CONFIGURE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} EGDIR=${EGDIR:Q}

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
