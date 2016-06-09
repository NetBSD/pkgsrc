# $NetBSD: Makefile,v 1.4 2016/06/09 06:23:40 wiz Exp $

DISTNAME=	ansiweather-1.06
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/ansiweather/
COMMENT=	Display current weather conditions in your terminal
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

USE_TOOLS+=	awk:run date:run grep:run

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	jq-[0-9]*:../../devel/jq

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALL_UNSTRIPPED=	yes

DOCDIR=		share/doc/ansiweather
EGDIR=		share/examples/ansiweather

CONF_FILES+=	${EGDIR}/ansiweatherrc.example ${PKG_SYSCONFDIR}/ansiweatherrc

SUBST_CLASSES+=		config shebang
SUBST_FILES.config=	ansiweather
SUBST_SED.config=	-e 's,~/.ansiweatherrc,${PKG_SYSCONFDIR}/ansiweatherrc,'
SUBST_STAGE.config=	post-patch

AUTO_MKDIRS=	yes

do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/ansiweather ${DESTDIR}${PREFIX}/bin
.for f in AUTHORS ChangeLog README.md ansiweather.plugin.zsh
	${RUN}${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${RUN}${INSTALL_DATA} ${WRKSRC}/ansiweatherrc.example \
	                      ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
