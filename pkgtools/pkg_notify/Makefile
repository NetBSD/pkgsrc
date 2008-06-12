# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=	pkg_notify-0.4.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wp/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}/pkg_notify

EXAMPLEDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EXAMPLEDIR}/${PKGBASE}.list \
			${PKG_SYSCONFDIR}/${PKGBASE}.list

SUBST_CLASSES+=			pkg_notify
SUBST_MESSAGE.pkg_notify=	Setting up hardcoded path.
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_SED.pkg_notify=		-e 's|/usr/pkgsrc|${PKGSRCDIR}|'	\
				-e 's|/usr/pkg|${LOCALBASE}|g'		\
				-e 's|/usr/bin/make|${MAKE}|g'		\
				-e 's|/usr/pkg/bin/perl|${PERL5}|g'

INSTALLATION_DIRS=	bin ${EXAMPLEDIR} share/doc/pkg_notify

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pkg_notify.list ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pkg_notify

.include "../../mk/bsd.pkg.mk"
