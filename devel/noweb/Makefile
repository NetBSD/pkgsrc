# $NetBSD: Makefile,v 1.26 2003/06/02 01:20:35 jschauma Exp $
# FreeBSD Id: Makefile,v 1.10 1997/09/15 07:22:06 tg Exp
#

DISTNAME=		noweb-2.9a
PKGREVISION=		1
WRKSRC=			${WRKDIR}/src
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.cs.virginia.edu/~nr/noweb/
COMMENT=		Simple, extensible literate-programming tool

DEPENDS=		icon>=9.3:../../lang/icon

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
do-configure:
	(cd ${WRKSRC} ; ./awkname awk)
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/noweb
	${INSTALL_DATA} ${WRKDIR}/examples/* ${PREFIX}/share/examples/noweb

.include "../../mk/bsd.pkg.mk"
