# $NetBSD: Makefile,v 1.33 2022/06/28 11:35:38 wiz Exp $

DISTNAME=	nikto-2.1.5
PKGREVISION=	7
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/nikto/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cirt.net/code/nikto.shtml
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_TOOLS+=	perl:run
REPLACE_PERL=	nikto.pl
NO_BUILD=	yes
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	nikto.pl docs/nikto.1
SUBST_SED.conf=		-e "s|/etc/nikto\.conf|${PKG_SYSCONFDIR}/nikto.conf|g"
SUBST_SED.conf+=	-e "s|/etc/nikto\\\&\.conf|${PKG_SYSCONFDIR}/nikto\\\\\\&.conf|g"
SUBST_MESSAGE.conf=	Fixing path to nikto.conf

SUBST_CLASSES+=		execdir
SUBST_STAGE.execdir=	pre-configure
SUBST_FILES.execdir=	nikto.conf
SUBST_SED.execdir=	-e "s|^\# EXECDIR=/opt/nikto|EXECDIR=${PREFIX}/libdata/nikto|g"
SUBST_MESSAGE.execdir=	Fixing path to EXECDIR

SUBST_CLASSES+=		manual
SUBST_STAGE.manual=	pre-configure
SUBST_FILES.manual=	docs/nikto.1
SUBST_SED.manual=	-e "s|/usr/local/bin/nikto|nikto|g"
SUBST_MESSAGE.manual=	Fixing path to nikto

CONF_FILES=	${PREFIX}/share/examples/nikto/nikto.conf \
			 ${PREFIX}/${PKG_SYSCONFDIR}/nikto.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.txt ${DESTDIR}${PREFIX}/libdata/nikto/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DESTDIR}${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/nikto.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/nikto.conf ${DESTDIR}${PREFIX}/share/examples/nikto
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${DESTDIR}${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/databases/db_* \
	    ${DESTDIR}${PREFIX}/libdata/nikto/databases
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin \
	    ${DESTDIR}${PREFIX}/libdata/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/templates/*.tmpl \
	    ${DESTDIR}${PREFIX}/libdata/nikto/templates
	${INSTALL_DATA} ${WRKSRC}/plugins/JSON-PP.pm ${DESTDIR}${PREFIX}/libdata/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/LW2.pm ${DESTDIR}${PREFIX}/libdata/nikto/plugins

.include "../../mk/bsd.pkg.mk"
