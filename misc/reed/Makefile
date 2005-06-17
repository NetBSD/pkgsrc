# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:22 jlam Exp $

DISTNAME=	reed-5.4
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.sacredchao.net/software/reed/index.shtml
COMMENT=	Auto-scrolling file viewer

CONFIGURE_SCRIPT=	./configures
CONFIGURE_ARGS+=	-p ${PREFIX}
HAS_CONFIGURE=		YES
USE_PERL5=		YES
REPLACE_PERL=		breed fix_bookmarks.pl wrap

# wgetnstr()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-U]-*

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/breed.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/reed.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/wrap.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/reed
	${INSTALL_DATA} ${WRKSRC}/help ${PREFIX}/share/reed/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
