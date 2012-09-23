# $NetBSD: Makefile,v 1.52 2012/09/23 05:36:22 obache Exp $

DISTNAME=	abcde-2.3.99.7_p235
PKGNAME=	abcde-2.3.99.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	sekiya@NetBSD.org
HOMEPAGE=	http://code.google.com/p/abcde/
COMMENT=	Command-line utility to rip and encode an audio CD

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	id3v2-[0-9]*:../../audio/id3v2
.if ${OPSYS} != "SunOS"
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
.endif
DEPENDS+=	mkcue>=2.1:../../misc/mkcue

NO_BUILD=	yes
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	bash:run gsed:run
REPLACE_BASH=	abcde cddb-tool

EGDIR=		${PREFIX}/share/examples/abcde

MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		abcde
SUBST_STAGE.abcde=	pre-configure
SUBST_MESSAGE.abcde=	Adjusting the directory for configuration files
SUBST_FILES.abcde=	abcde abcde.1
SUBST_SED.abcde=	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"

SUBST_CLASSES+=		gsed
SUBST_STAGE.gsed=	pre-configure
SUBST_MESSAGE.gsed=	Adjusting gsed path
SUBST_FILES.gsed=	abcde
SUBST_SED.gsed=		-e "s,@TOOLS_GSED@,${TOOLS_PATH.gsed},g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/abcde.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.if ${OPSYS} == "SunOS"
USE_TOOLS+=	ftp:run

SUBST_CLASSES+=		abcde-cdparanoia
SUBST_STAGE.abcde-cdparanoia=	pre-configure
SUBST_MESSAGE.abcde-cdparanoia=	Adjusting cd-paranoia command name
SUBST_FILES.abcde-cdparanoia=	abcde abcde.conf
SUBST_SED.abcde-cdparanoia=	-e "/CDPARANOIA=cdparanoia/s/cdparanoia/cd-paranoia/"

.include "../../misc/libcdio/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
