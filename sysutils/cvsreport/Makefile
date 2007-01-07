# $NetBSD: Makefile,v 1.3 2007/01/07 09:14:11 rillig Exp $
#

DISTNAME=		cvsreport-0.3.5
CATEGORIES=		sysutils
MASTER_SITES=		http://download.gna.org/cvsreport/cvsreport.pkg/0.3.5/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://home.gna.org/cvsreport/
COMMENT=		Message reports from CVS activity

REPLACE_PERL+=		cvsreport
USE_TOOLS+=		perl:run
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsreport ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cvsreport.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
