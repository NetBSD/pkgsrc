# $NetBSD: Makefile,v 1.55 2020/04/12 08:28:33 adam Exp $

DISTNAME=	OpenGrok-0.12.1.5
PKGNAME=	${DISTNAME:tl:S/-rc/rc/}
PKGREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenGrok/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opengrok.github.io/OpenGrok/
COMMENT=	Fast and usable source code search and cross reference engine
LICENSE=	cddl-1.0

EXTRACT_USING=	bsdtar

DEPENDS+=	exctags-[0-9]*:../../devel/exctags
DEPENDS+=	jflex-[0-9]*:../../devel/jflex
DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

# XXX PREFIX should not be used here, but I would like to reduce dependencies.
SUBST_CLASSES+=		vcs
SUBST_FILES.vcs+=	OpenGrok
SUBST_MESSAGE.vcs=	Set VCS program pathes.
SUBST_STAGE.vcs=	pre-configure
SUBST_VARS.vcs=		PREFIX

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	web/WEB-INF/web.xml
SUBST_MESSAGE.conf=	Set configuration.xml location
SUBST_STAGE.conf=	pre-configure
SUBST_VARS.conf=	PREFIX

MESSAGE_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME}

.include "options.mk"

USE_JAVA=	yes
USE_JAVA2=	yes
USE_TOOLS+=	unzip:run zip:run

CONF_FILES=	${PREFIX}/share/examples/opengrok/paths.tsv \
		${PREFIX}/share/opengrok/var/opengrok/paths.tsv

INSTALLATION_DIRS+=	share/opengrok/bin \
			share/opengrok/lib/lib \
			share/examples/opengrok \
			share/opengrok/var/opengrok

do-build:
	cd ${WRKSRC} && \
		CLASSPATH=${PREFIX}/lib/java/JFlex.jar ${PREFIX}/bin/ant

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/OpenGrok \
		${DESTDIR}${PREFIX}/share/opengrok/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/dist/opengrok.jar \
		${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/dist/source.war \
		${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar \
		${DESTDIR}${PREFIX}/share/opengrok/lib/lib
	${INSTALL_DATA} ${WRKSRC}/paths.tsv \
		${DESTDIR}${PREFIX}/share/examples/opengrok

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
