# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 00:26:21 xtraeme Exp $
#

DISTNAME=	pkg_notify-0.3.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

WRKSRC=		${WRKDIR}/pkg_notify

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=	pkg_notify
SUBST_MESSAGE.pkg_notify=	"Setting up hardcoded path."
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_SED.pkg_notify=		-e 's|/usr/pkgsrc|${PKGSRCDIR}|'	\
				-e 's|/usr/pkg|${LOCALBASE}|g'		\
				-e 's|/usr/bin/make|${MAKE}|g'		\
				-e 's|/usr/pkg/bin/perl|${PERL5}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
