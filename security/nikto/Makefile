# $NetBSD: Makefile,v 1.23 2016/07/09 06:38:55 wiz Exp $

DISTNAME=	nikto-1.36
PKGREVISION=	5
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/nikto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cirt.net/code/nikto.shtml
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay
DEPENDS+=	nmap>=2.00:../../net/nmap

USE_TOOLS+=	perl:run
REPLACE_PERL=	nikto.pl
NO_BUILD=	YES

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	config.txt
SUBST_SED.conf=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing PREFIX in files.

CONF_FILES=	${PREFIX}/share/examples/nikto/config.txt \
			 ${PREFIX}/share/nikto/config.txt

INSTALLATION_DIRS=	bin libdata/nikto/docs libdata/nikto/plugins \
			share/doc/nikto share/examples/nikto share/nikto

do-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.txt ${DESTDIR}${PREFIX}/libdata/nikto/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DESTDIR}${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/config.txt ${DESTDIR}${PREFIX}/share/examples/nikto
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${DESTDIR}${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin \
	    ${DESTDIR}${PREFIX}/libdata/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/LW.pm ${DESTDIR}${PREFIX}/libdata/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.db ${DESTDIR}${PREFIX}/libdata/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.txt ${DESTDIR}${PREFIX}/libdata/nikto/plugins

.include "../../mk/bsd.pkg.mk"
