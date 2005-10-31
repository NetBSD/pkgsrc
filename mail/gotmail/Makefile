# $NetBSD: Makefile,v 1.1.1.1 2005/10/31 20:34:19 minskim Exp $
#

DISTNAME=		gotmail-0.8.6
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gotmail/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sourceforge.net/projects/gotmail
COMMENT=		Script to download mail from hotmail.com

DEPENDS+=		curl-[0-9]*:../../www/curl
DEPENDS+=		p5-URI>=1.03:../../www/p5-URI
DEPENDS+=		p5-Net-[0-9]*:../../net/p5-Net

USE_PKGINSTALL=		yes
USE_TOOLS+=		perl:run
REPLACE_PERL=		${WRKSRC}/gotmail.in

PKG_SYSCONFSUBDIR=	gotmail

EGDIR=			${PREFIX}/share/examples/gotmail
CONF_FILES=		${EGDIR}/sample.gotmailrc \
			${PKG_SYSCONFDIR}/sample.gotmailrc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gotmail ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gotmail
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gotmail
	${INSTALL_DATA} ${WRKSRC}/sample.gotmailrc ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/gotmail.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
