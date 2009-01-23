# $NetBSD: Makefile,v 1.1.1.1 2009/01/23 13:35:30 sborrill Exp $
#

DISTNAME=	proxytunnel-1.9.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=proxytunnel/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://proxytunnel.sourceforge.net/
COMMENT=	Connect stdin/stdout to a remote host through a standard HTTPS proxy

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake
BUILD_TARGET=	proxytunnel
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 bin

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		proxytunnel.1
SUBST_SED.fix-paths=		-e 's,/usr,${PREFIX},g'

do-install:
	${INSTALL} ${WRKSRC}/proxytunnel ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxytunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
