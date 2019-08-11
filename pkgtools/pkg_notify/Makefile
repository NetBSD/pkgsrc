# $NetBSD: Makefile,v 1.30 2019/08/11 13:22:36 wiz Exp $

PKGNAME=	pkg_notify-0.4.6
PKGREVISION=	2
CATEGORIES=	pkgtools

MAINTAINER=	imil@gcu.info
HOMEPAGE=	# none
COMMENT=	Notifies package maintainer when a new version is available
LICENSE=	modified-bsd

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/${PKGBASE}.list \
			${PKG_SYSCONFDIR}/${PKGBASE}.list

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			pkg_notify
SUBST_STAGE.pkg_notify=		pre-install
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_FILES.pkg_notify+=	pkg_notify.1
SUBST_VARS.pkg_notify=		PKGSRCDIR
SUBST_VARS.pkg_notify+=		PREFIX
SUBST_VARS.pkg_notify+=		MAKE
SUBST_SED.pkg_notify+=		-e 's|@PERL@|${PERL5:Q}|g'
SUBST_VARS.pkg_notify+=		PKG_SYSCONFDIR

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
