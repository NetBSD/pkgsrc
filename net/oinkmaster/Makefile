# $NetBSD: Makefile,v 1.5 2005/05/02 10:48:16 adrianp Exp $

DISTNAME=	oinkmaster-1.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oinkmaster/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://oinkmaster.sourceforge.net/
COMMENT=	Manage snort rule updates

DEPENDS+=	wget>=1.00:../../net/wget
DEPENDS+=	snort{,-mysql,-pgsql}-[0-9]*:../../net/snort

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

PKG_SYSCONFSUBDIR=	snort

SUBST_CLASSES=		pub
SUBST_STAGE.pub=	post-patch
SUBST_FILES.pub=	oinkmaster.pl oinkmaster.conf oinkmaster.1
SUBST_SED.pub=		-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g" \
			-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.pub=	"Fixing harcoded paths."

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
	${LN} -s ${PKG_SYSCONFDIR}/classification.config \
		${PREFIX}/share/snort/rules/classification.config
	${LN} -s ${PKG_SYSCONFDIR}/reference.config \
		${PREFIX}/share/snort/rules/reference.config
	${LN} -s ${PKG_SYSCONFDIR}/gen-msg.map \
		${PREFIX}/share/snort/rules/gen-msg.map
	${LN} -s ${PKG_SYSCONFDIR}/sid-msg.map \
		${PREFIX}/share/snort/rules/sid-msg.map
	${LN} -s ${PKG_SYSCONFDIR}/unicode.map \
		${PREFIX}/share/snort/rules/unicode.map

.include "../../mk/bsd.pkg.mk"
