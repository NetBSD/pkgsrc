# $NetBSD: Makefile,v 1.1.1.1 2004/05/17 09:27:57 minskim Exp $

DISTNAME=	bitchbot-1.0.2
CATEGORIES=	chat
MASTER_SITES=	http://www.r1ch.net/projects/bitchbot/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.r1ch.net/projects/bitchbot/
COMMENT=	Bitchbot is a perl-based IRC bot

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	YES
USE_PKGINSTALL=	YES
NO_BUILDLINK=	YES

REPLACE_PERL=	bitch.pl genstats.pl

CONF_FILES=	${PREFIX}/share/examples/bitch/bitch.conf.template \
		${PKG_SYSCONFDIR}/bitch.conf

INSTALLATION_DIRS=	bin

do-build:
	@${SED} -e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/bitch.pl > ${WRKSRC}/bitch;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bitch

	${INSTALL_SCRIPT} ${WRKSRC}/bitch ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/genstats.pl ${PREFIX}/bin/genstats
	${INSTALL_DATA}	${WRKSRC}/bitch.conf.template \
		${PREFIX}/share/examples/bitch

.include "../../mk/bsd.pkg.mk"
