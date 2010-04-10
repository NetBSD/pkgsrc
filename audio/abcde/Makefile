# $NetBSD: Makefile,v 1.43 2010/04/10 13:20:11 sekiya Exp $

DISTNAME=	abcde-2.3.99.7_p235
PKGNAME=	abcde-2.3.99.7
#PKGREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	sekiya@NetBSD.org
#HOMEPAGE=	http://www.hispalinux.es/~data/abcde.php
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	id3v2-[0-9]*:../../audio/id3v2
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	bash>=3.0:../../shells/bash
DEPENDS+=	mkcue>=2.1:../../misc/mkcue
DEPENDS+=	gsed>=4.2:../../textproc/gsed

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

EGDIR=		${PREFIX}/share/examples/abcde

MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		abcde
SUBST_STAGE.abcde=	pre-configure
SUBST_MESSAGE.abcde=	Adjusting the directory for configuration files
SUBST_FILES.abcde=	abcde abcde.1
SUBST_SED.abcde=	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/abcde.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
