# $NetBSD: Makefile,v 1.28 2019/08/11 13:22:13 wiz Exp $

DISTNAME=	oinkmaster-2.0
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oinkmaster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oinkmaster.sourceforge.net/
COMMENT=	Manage snort rule updates
LICENSE=	modified-bsd

DEPENDS+=	snort{,-mysql,-pgsql}-[0-9]*:../../net/snort

NO_BUILD=	yes

CONF_FILES=	${PREFIX}/share/examples/oinkmaster/oinkmaster.conf \
		${PKG_SYSCONFDIR}/oinkmaster.conf
EGDIR=		${PREFIX}/share/examples/oinkmaster
DOCDIR=		${PREFIX}/share/doc/oinkmaster
DOCS=		INSTALL LICENSE README README.templates UPGRADING FAQ

USE_TOOLS+=	perl:run
REPLACE_PERL+=	${WRKSRC}/oinkmaster.pl

.include "options.mk"

PKG_SYSCONFSUBDIR=	snort

SUBST_CLASSES+=		pub
SUBST_STAGE.pub=	pre-configure
SUBST_FILES.pub=	oinkmaster.pl oinkmaster.conf oinkmaster.1
SUBST_SED.pub=		-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_SED.pub+=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.pub=	Fixing harcoded paths.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 \
			share/doc/oinkmaster share/examples/oinkmaster \
			share/snort/rules

do-install:
.	for f in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/template-examples.conf ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/oinkmaster.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${DESTDIR}${PREFIX}/bin/oinkmaster
	${LN} -s ${PKG_SYSCONFDIR}/classification.config \
	    ${DESTDIR}${PREFIX}/share/snort/rules/classification.config
	${LN} -s ${PKG_SYSCONFDIR}/reference.config \
	    ${DESTDIR}${PREFIX}/share/snort/rules/reference.config
	${LN} -s ${PKG_SYSCONFDIR}/gen-msg.map \
	    ${DESTDIR}${PREFIX}/share/snort/rules/gen-msg.map
	${LN} -s ${PKG_SYSCONFDIR}/sid-msg.map \
	    ${DESTDIR}${PREFIX}/share/snort/rules/sid-msg.map
	${LN} -s ${PKG_SYSCONFDIR}/unicode.map \
	    ${DESTDIR}${PREFIX}/share/snort/rules/unicode.map

.include "../../mk/bsd.pkg.mk"
