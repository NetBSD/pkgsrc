# $NetBSD: Makefile,v 1.5 2005/01/14 10:04:01 jmmv Exp $
#

DISTNAME=	pkg_notify-0.4.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes
NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
USE_PERL5=		yes
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}/pkg_notify

EXAMPLEDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EXAMPLEDIR}/${PKGBASE}.list \
			${PKG_SYSCONFDIR}/${PKGBASE}.list

SUBST_CLASSES+=			pkg_notify
SUBST_MESSAGE.pkg_notify=	"Setting up hardcoded path."
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_SED.pkg_notify=		-e 's|/usr/pkgsrc|${PKGSRCDIR}|'	\
				-e 's|/usr/pkg|${LOCALBASE}|g'		\
				-e 's|/usr/bin/make|${MAKE}|g'		\
				-e 's|/usr/pkg/bin/perl|${PERL5}|g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.list ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
