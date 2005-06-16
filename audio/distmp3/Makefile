# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:38 jlam Exp $
#

DISTNAME=		distmp3-0.1.9
CATEGORIES=		audio
MASTER_SITES=		http://distro.ibiblio.org/pub/linux/distributions/sorcerer/sources/distmp3/0.1.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		grant@NetBSD.org
COMMENT=		Distributed mp3 encoding across multiple hosts

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
TOOLS_DEPMETHOD.perl=	DEPENDS
USE_PKGINSTALL=		yes
NO_BUILD=		yes

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

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distmp3 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/distmp3host ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/distmp3.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/distmp3host.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/distmp3.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
