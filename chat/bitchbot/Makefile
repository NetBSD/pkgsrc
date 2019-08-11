# $NetBSD: Makefile,v 1.18 2019/08/11 13:18:02 wiz Exp $

DISTNAME=	bitchbot-1.0.2
PKGREVISION=	7
CATEGORIES=	chat
#MASTER_SITES=	http://www.r1ch.net/projects/bitchbot/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.r1ch.net/projects/bitchbot/
COMMENT=	Bitchbot is a perl-based IRC bot

USE_TOOLS+=	perl:run

REPLACE_PERL=	bitch.pl genstats.pl

CONF_FILES=	${PREFIX}/share/examples/bitch/bitch.conf.template \
		${PKG_SYSCONFDIR}/bitch.conf

INSTALLATION_DIRS=	bin

do-build:
	@${SED} -e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/bitch.pl > ${WRKSRC}/bitch;

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/bitch
	${INSTALL_SCRIPT} ${WRKSRC}/bitch ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/genstats.pl ${DESTDIR}${PREFIX}/bin/genstats
	${INSTALL_DATA}	${WRKSRC}/bitch.conf.template \
		${DESTDIR}${PREFIX}/share/examples/bitch

.include "../../mk/bsd.pkg.mk"
