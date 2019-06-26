# $NetBSD: Makefile,v 1.6 2019/06/26 13:14:54 sevan Exp $
#

DISTNAME=	wtf-20190623
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsdwtf/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://bsdwtf.sourceforge.net/
COMMENT=	Translate common Internet acronyms
LICENSE=	public-domain

NO_BUILD=	yes

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	wtf wtf.6
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_SED.paths=	-e 's|/usr/share/misc/|${PREFIX}/share/wtf/|g'
SUBST_STAGE.paths=	pre-configure

REPLACE_SH=		wtf

INSTALLATION_DIRS+=	bin share/wtf ${PKGMANDIR}/man6

post-extract:
	${RM} ${WRKSRC}/acronyms-o.fake
	${MV} ${WRKSRC}/acronyms-o.real ${WRKSRC}/acronyms-o

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/acronyms* ${DESTDIR}${PREFIX}/share/wtf
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/bsd.pkg.mk"
