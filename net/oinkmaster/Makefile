# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 09:36:09 xtraeme Exp $

DISTNAME=	oinkmaster-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.it.su.se/pub/users/andreas/oinkmaster/ \
		http://www.algonet.se/~nitzer/oinkmaster/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.algonet.se/~nitzer/oinkmaster/
COMMENT=	Manage snort rule updates

DEPENDS+=	wget>=1.00:../../net/wget

USE_PKGINSTALL=	yes
USE_BUILDLINK3=	yes
USE_PERL5=	yes
NO_BUILD=	yes

CONF_FILES=	${PREFIX}/share/examples/oinkmaster/oinkmaster.conf \
		${PKG_SYSCONFDIR}/oinkmaster.conf

REPLACE_PERL+=	${WRKSRC}/oinkmaster.pl

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/oinkmaster

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf \
		${PREFIX}/share/examples/oinkmaster
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${PREFIX}/bin/oinkmaster

SUBST_CLASSES=	    pub
SUBST_STAGE.pub=    post-patch
SUBST_FILES.pub=    oinkmaster.pl oinkmaster.conf
SUBST_SED.pub=	    -e "s|/usr/local|${PREFIX}|g" \
		    -e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.pub=  "Fixing harcoded PATH."

.include "../../mk/bsd.pkg.mk"
