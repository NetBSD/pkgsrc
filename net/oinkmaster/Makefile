# $NetBSD: Makefile,v 1.4 2005/04/27 19:50:48 adrianp Exp $

DISTNAME=	oinkmaster-1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oinkmaster/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://oinkmaster.sourceforge.net/
COMMENT=	Manage snort rule updates

DEPENDS+=	wget>=1.00:../../net/wget

USE_PKGINSTALL=	yes
USE_PERL5=	yes
NO_BUILD=	yes

CONF_FILES=	${PREFIX}/share/examples/oinkmaster/oinkmaster.conf \
		${PKG_SYSCONFDIR}/oinkmaster.conf
PERL5_REQD+=	5.6.1
EGDIR=		${PREFIX}/share/examples/oinkmaster	
DOCDIR=		${PREFIX}/share/doc/oinkmaster
DOCS=		INSTALL LICENSE README README.templates UPGRADING FAQ

REPLACE_PERL+=	${WRKSRC}/oinkmaster.pl
MESSAGE_SUBST+=	LN=${LN}

SUBST_CLASSES=	    pub
SUBST_STAGE.pub=    post-patch
SUBST_FILES.pub=    oinkmaster.pl oinkmaster.conf oinkmaster.1
SUBST_SED.pub=	    -e "s|/usr/local|${PREFIX}|g" \
		    -e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.pub=  "Fixing harcoded paths."

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/oinkmaster

.	for f in ${DOCS}                  
		${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/${f}
.	endfor                               
.	undef f

	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/template-examples.conf ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/oinkmaster.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${PREFIX}/bin/oinkmaster

.include "../../mk/bsd.pkg.mk"
