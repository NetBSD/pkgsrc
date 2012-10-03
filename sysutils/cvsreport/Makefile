# $NetBSD: Makefile,v 1.7 2012/10/03 21:57:37 wiz Exp $
#

DISTNAME=		cvsreport-0.3.5
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://download.gna.org/cvsreport/cvsreport.pkg/0.3.5/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/cvsreport/
COMMENT=		Message reports from CVS activity
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=		cvsreport
USE_TOOLS+=		perl:run
NO_BUILD=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsreport ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cvsreport.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
