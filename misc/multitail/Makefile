# $NetBSD: Makefile,v 1.30 2017/01/05 16:08:18 roy Exp $
#

DISTNAME=	multitail-4.0.6
PKGREVISION=	5
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files

INCOMPAT_CURSES+=	NetBSD-[0-6].*-* NetBSD-7.[0-9].* # needs libpanel
FAKE_NCURSES=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/multitail	\
			share/examples/multitail

CONF_FILES=	${PREFIX:Q}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR:Q}/multitail.conf

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil
LDFLAGS.SunOS+=			-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/multitail ${DESTDIR}${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/multitail.1 \
		${DESTDIR}${PREFIX:Q}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC:Q}/multitail.conf \
		${DESTDIR}${PREFIX:Q}/share/examples/multitail/
	cd ${WRKSRC:Q} && ${INSTALL_DATA} *.txt manual*.html \
		${DESTDIR}${PREFIX:Q}/share/doc/multitail/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
