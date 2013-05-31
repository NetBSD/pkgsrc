# $NetBSD: Makefile,v 1.23 2013/05/31 12:41:29 wiz Exp $

DISTNAME=	reed-5.4
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sacredchao.net/software/reed/index.shtml
COMMENT=	Auto-scrolling file viewer

CONFIGURE_SCRIPT=	./configures
CONFIGURE_ARGS+=	-p ${PREFIX}
HAS_CONFIGURE=		YES
USE_TOOLS+=		perl:run
REPLACE_PERL=		breed fix_bookmarks.pl wrap

# wgetnstr()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-U]-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/breed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/reed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/wrap.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/reed
	${INSTALL_DATA} ${WRKSRC}/help ${DESTDIR}${PREFIX}/share/reed/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
