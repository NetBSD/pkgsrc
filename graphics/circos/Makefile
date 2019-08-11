# $NetBSD: Makefile,v 1.13 2019/08/11 13:21:08 wiz Exp $
#

DISTNAME=	circos-0.49
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://mkweb.bcgsc.ca/circos/distribution/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mkweb.bcgsc.ca/circos/
COMMENT=	Concise, explanatory, unique and print-ready data visualization
#LICENSE=

USE_LANGUAGES=	# none
USE_TOOLS+=	pax perl bash:run
NO_BUILD=	yes

DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Config-General-[0-9]*:../../devel/p5-Config-General
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Math-Bezier-[0-9]*:../../math/p5-Math-Bezier
DEPENDS+=	p5-Math-Round-[0-9]*:../../math/p5-Math-Round
DEPENDS+=	p5-Math-VecStat-[0-9]*:../../math/p5-Math-VecStat
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate
DEPENDS+=	p5-Set-IntSpan>=1.11:../../devel/p5-Set-IntSpan

PKG_SYSCONFSUBDIR=	${PKGBASE}
INSTALLATION_DIRS+=	bin share/${PKGBASE} ${FONTDIR} ${EGDIR}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}

CONF_FILES+=		${EGDIR}/colors.conf ${PKG_SYSCONFDIR}/colors.conf
CONF_FILES+=		${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	*/*/*/circos*.conf bin/circos
SUBST_SED.paths+=	-e 's|<<include etc/\(.*\)>>|<<include ${PKG_SYSCONFDIR}/\1>>|g'
SUBST_VARS.paths=	PREFIX

REPLACE_PERL+=	data/3/make_random_highlights data/6/hist.random.make
REPLACE_PERL+=	svg/textrotation.svg

REPLACE_BASH+=	data/6/gene.density

post-extract:
	cd ${WRKSRC} && rm -f bin/${PKGBASE} \
		&& mv bin/${PKGNAME_NOREV} bin/${PKGBASE}

do-configure:
	cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install

pre-configure:
	cd ${WRKSRC} && rm -f bin/*.orig

do-install:
	cd ${WRKSRC} &&							\
	for f in CHANGES README TODO; do				\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE};	\
	done;								\
	for f in bin/*; do						\
		${INSTALL_SCRIPT} $${f} ${DESTDIR}${PREFIX}/bin;			\
	done;								\
	for f in etc/*; do						\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${EGDIR};		\
	done;								\
	pax -rw -pp data fonts images svg tutorials ${DESTDIR}${PREFIX}/share/circos

.include "../../mk/bsd.pkg.mk"
