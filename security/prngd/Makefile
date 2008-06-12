# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:45 joerg Exp $

DISTNAME=		prngd-0.9.29
CATEGORIES=		security
MASTER_SITES=		http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/prng-and-entropy/prngd/ \
			ftp://ftp.mirrors.wiretapped.net/pub/security/cryptography/libraries/math/prng-and-entropy/prngd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aet.tu-cottbus.de/personen/jaenicke/postfix_tls/prngd.html
COMMENT=		Pseudo Random Number Generator Daemon

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		DEFS='-DRANDSAVENAME="\"${VARBASE}/db/prngd-seed\"" -DCONFIGFILE="\"${PKG_SYSCONFDIR}/prngd.conf\""'

EGDIR=			${PREFIX}/share/examples/prngd
CONF_FILES=		${EGDIR}/prngd.conf.netbsd ${PKG_SYSCONFDIR}/prngd.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/prngd share/examples/prngd

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-install
SUBST_MESSAGE.path=	Fixing paths in man page.
SUBST_FILES.path=	prngd.man
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.path+=	-e 's,/var,${VARBASE},g'

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prngd ${DESTDIR}${PREFIX}/bin/prngd
	${INSTALL_DATA} ${WRKSRC}/00README ${DESTDIR}${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/00README.gatherers ${DESTDIR}${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/00DESIGN ${DESTDIR}${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/contrib/NetBSD1/prngd.conf.netbsd ${DESTDIR}${PREFIX}/share/examples/prngd
	${INSTALL_MAN} ${WRKSRC}/prngd.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/prngd.1

.include "../../mk/bsd.pkg.mk"
