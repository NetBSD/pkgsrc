# $NetBSD: Makefile,v 1.25 2016/02/25 15:35:31 jperkin Exp $
#

DISTNAME=	multitail-4.0.6
PKGREVISION=	3
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files

USE_NCURSES=		yes	# Needs the <panel> library.
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/multitail	\
			share/examples/multitail

CONF_FILES=	${PREFIX:Q}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR:Q}/multitail.conf

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil
LDFLAGS.SunOS+=			-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/multitail ${DESTDIR}${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/multitail.1 ${DESTDIR}${PREFIX:Q}/man/man1/
	${INSTALL_DATA} ${WRKSRC:Q}/multitail.conf \
		${DESTDIR}${PREFIX:Q}/share/examples/multitail/
	cd ${WRKSRC:Q} && ${INSTALL_DATA} *.txt manual*.html \
		${DESTDIR}${PREFIX:Q}/share/doc/multitail/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
