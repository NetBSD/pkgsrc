# $NetBSD: Makefile,v 1.8 2005/09/03 11:01:35 adrianp Exp $

DISTNAME=	nikto-1.35
PKGREVISION=	1
DIST_SUBDIR=    ${PKGNAME}
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/nikto/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.cirt.net/code/nikto.shtml
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay
DEPENDS+=	nmap>=2.00:../../net/nmap

USE_TOOLS+=	perl:run
REPLACE_PERL=	nikto.pl
NO_BUILD=	YES
USE_PKGINSTALL=	YES

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	config.txt
SUBST_SED.conf=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.conf=	"Fixing PREFIX in files."

CONF_FILES=	${PREFIX}/share/examples/nikto/config.txt \
			 ${PREFIX}/share/nikto/config.txt

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nikto
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto/docs
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.txt ${PREFIX}/share/nikto/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/config.txt \
		${PREFIX}/share/examples/nikto
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/LW.pm ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.db ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.txt ${PREFIX}/share/nikto/plugins

.include "../../mk/bsd.pkg.mk"
