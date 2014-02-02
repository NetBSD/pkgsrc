# $NetBSD: Makefile,v 1.17 2014/02/02 10:19:41 wiz Exp $

DISTNAME=	pkg_notify-0.4.4
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	imil@gcu.info
HOMEPAGE=	# none
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/${PKGBASE}.list \
			${PKG_SYSCONFDIR}/${PKGBASE}.list

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			pkg_notify
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_FILES.pkg_notify+=	pkg_notify.1
SUBST_SED.pkg_notify=		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|'
SUBST_SED.pkg_notify+=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.pkg_notify+=		-e 's|@MAKE@|${MAKE:Q}|g'
SUBST_SED.pkg_notify+=		-e 's|@PERL@|${PERL5:Q}|g'
SUBST_SED.pkg_notify+=		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin ${EGDIR} ${PKGMANDIR}/man1

do-extract:
	cd ${FILESDIR} &&	\
	${CP} pkg_notify pkg_notify.list pkg_notify.1 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pkg_notify.list ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/pkg_notify.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
