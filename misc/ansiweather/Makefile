# $NetBSD: Makefile,v 1.14 2020/06/16 09:21:57 fcambus Exp $

DISTNAME=	ansiweather-1.17.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/ansiweather/
COMMENT=	Display current weather conditions in your terminal
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

USE_TOOLS+=	cut:run date:run grep:run

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	jq-[0-9]*:../../devel/jq

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALL_UNSTRIPPED=	yes

DOCDIR=		share/doc/ansiweather
EGDIR=		share/examples/ansiweather

CONF_FILES+=	${EGDIR}/ansiweatherrc.example ${PKG_SYSCONFDIR}/ansiweatherrc

SUBST_CLASSES+=		config
SUBST_FILES.config=	ansiweather
SUBST_SED.config=	-e 's,~/.ansiweatherrc,${PKG_SYSCONFDIR}/ansiweatherrc,'
SUBST_STAGE.config=	pre-configure

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/ansiweather ${DESTDIR}${PREFIX}/bin
.for f in AUTHORS ChangeLog README.md ansiweather.plugin.zsh
	${RUN}${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${RUN}${INSTALL_MAN} ${WRKSRC}/ansiweather.1 \
	                     ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RUN}${INSTALL_DATA} ${WRKSRC}/ansiweatherrc.example \
	                      ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
