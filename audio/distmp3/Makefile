# $NetBSD: Makefile,v 1.1.1.1 2005/02/13 11:55:56 grant Exp $
#

DISTNAME=		distmp3-0.1.9
CATEGORIES=		audio
MASTER_SITES=		http://distro.ibiblio.org/pub/linux/distributions/sorcerer/sources/distmp3/0.1.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		grant@NetBSD.org
COMMENT=		Distributed mp3 encoding across multiple hosts

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
USE_PERL5=		# defined
USE_PKGINSTALL=		yes
NO_BUILD=		# defined

EGDIR=			${PREFIX}/share/examples/distmp3
CONF_FILES=		${EGDIR}/distmp3.conf ${PKG_SYSCONFDIR}/distmp3.conf
REPLACE_PERL=		distmp3 distmp3host

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing configuration file path."
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	distmp3 distmp3.1 distmp3host distmp3host.1
SUBST_SED.paths=	-e 's,/etc/distmp3,${PKG_SYSCONFDIR},'

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	"Fixing configuration file parameters."
SUBST_STAGE.config=	post-configure
SUBST_FILES.config=	distmp3.conf
SUBST_SED.config+=	-e 's,^SERVER_PROGRAM,; SERVER_PROGRAM,'
SUBST_SED.config+=	-e 's,/usr/local,${PREFIX},'

#HOMEPAGE=
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distmp3 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/distmp3host ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/distmp3.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/distmp3host.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/distmp3.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
