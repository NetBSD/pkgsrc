# $NetBSD: Makefile,v 1.35 2018/08/22 09:45:46 wiz Exp $

DISTNAME=	reed-5.4
PKGREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.sacredchao.net/software/reed/index.shtml
COMMENT=	Auto-scrolling file viewer

CONFIGURE_SCRIPT=	./configures
CONFIGURE_ARGS+=	-p ${PREFIX}
HAS_CONFIGURE=		YES
USE_TOOLS+=		perl:run
REPLACE_PERL=		breed fix_bookmarks.pl wrap

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES.SunOS+=	sysdir1 sysdir2
SUBST_STAGE.sysdir1=	pre-configure
SUBST_FILES.sysdir1=	cfg.data
SUBST_SED.sysdir1=	-e "s,sys/dir.h,,g"
SUBST_STAGE.sysdir2=	pre-configure
SUBST_FILES.sysdir2=	reed.c
SUBST_SED.sysdir2=	-e "/sys\/dir.h/d"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/breed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/reed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/wrap.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/reed
	${INSTALL_DATA} ${WRKSRC}/help ${DESTDIR}${PREFIX}/share/reed/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
