# $NetBSD: Makefile,v 1.32 2006/03/04 21:29:18 jlam Exp $

DISTNAME=		noweb-2.9a
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.virginia.edu/~nr/noweb/
COMMENT=		Simple, extensible literate-programming tool

DEPENDS+=		icon>=9.3:../../lang/icon

WRKSRC=			${WRKDIR}/src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
do-configure:
	(cd ${WRKSRC} ; ./awkname awk)
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/noweb
	${INSTALL_DATA} ${WRKDIR}/examples/* ${PREFIX}/share/examples/noweb

.include "../../mk/bsd.pkg.mk"
