# $NetBSD: Makefile,v 1.14 2023/10/24 22:10:30 wiz Exp $
#

DISTNAME=	proxytunnel-1.9.0
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=proxytunnel/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://proxytunnel.sourceforge.io/
COMMENT=	Connect stdin/stdout to a remote host through a standard HTTPS proxy

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
BUILD_TARGET=		proxytunnel
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 bin

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		proxytunnel.1
SUBST_SED.fix-paths=		-e 's,/usr,${PREFIX},g'

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
	${INSTALL} ${WRKSRC}/proxytunnel ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxytunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
