# $NetBSD: Makefile,v 1.67 2018/08/22 09:42:54 wiz Exp $

DISTNAME=	abcde-2.9.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://abcde.einval.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abcde.einval.com/
COMMENT=	Command-line utility to rip and encode an audio CD
LICENSE=	gnu-gpl-v2

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	eyeD3-[0-9]*:../../audio/eyeD3
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	p5-MusicBrainz-DiscID-[0-9]*:../../audio/p5-MusicBrainz-DiscID
DEPENDS+=	p5-WebService-MusicBrainz>=1.0.4:../../net/p5-WebService-MusicBrainz
# depend on cdrkit for icedax?
DEPENDS+=	mkcue>=2.1:../../misc/mkcue

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	bash:run ftp:run gsed:run perl:run
REPLACE_BASH=	abcde cddb-tool
REPLACE_PERL+=	abcde-musicbrainz-tool

# even with all these installed, abcde-musicbrainz-tool does not work
#USE_TOOLS=	perl:run
#DEPENDS+=	p5-MusicBrainz-DiscID-[0-9]*:../../audio/p5-MusicBrainz-DiscID
#DEPENDS+=	p5-WebService-MusicBrainz-[0-9]*:../../net/p5-WebService-MusicBrainz

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
SUBST_SED.gsed=		-e "s, sed , ${TOOLS_PATH.gsed} ,g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/abcde-musicbrainz-tool ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/abcde.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
