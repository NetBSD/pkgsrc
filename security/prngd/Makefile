# $NetBSD: Makefile,v 1.2 2005/03/07 10:03:13 uebayasi Exp $

DISTNAME=		prngd-0.9.29
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.aet.tu-cottbus.de/pub/postfix_tls/related/prngd/ \
			ftp://ftp.ayamura.org/pub/prngd/ \
			ftp://ftp.win.ne.jp/pub/misc/prngd/ \
			http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/prng-and-entropy/prngd/ \
			ftp://ftp.mirrors.wiretapped.net/pub/security/cryptography/libraries/math/prng-and-entropy/prngd/ \
			http://planetmirror.com/pub/solaris-random/prngd/ \
			ftp://planetmirror.com/pub/solaris-random/prngd/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.aet.tu-cottbus.de/personen/jaenicke/postfix_tls/prngd.html
COMMENT=		Pseudo Random Number Generator Daemon

MAKE_ENV+=		DEFS='-DRANDSAVENAME="\"${VARBASE}/db/prngd-seed\"" -DCONFIGFILE="\"${PKG_SYSCONFDIR}/prngd.conf\""'

EGDIR=          ${PREFIX}/share/examples/prngd
CONF_FILES=     ${EGDIR}/prngd.conf.netbsd ${PKG_SYSCONFDIR}/prngd.conf

INSTALLATION_DIRS=	bin man/man1

SUBST_CLASSES=          path
SUBST_STAGE.path=       pre-install
SUBST_FILES.path=       prngd.man
SUBST_SED.path=         -e 's,/usr/local,${PREFIX},g'
SUBST_SED.path+=	-e 's,/var,${VARBASE},g'
SUBST_MESSAGE.path=     "Fixing paths in man page."

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prngd ${PREFIX}/bin/prngd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/prngd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/prngd
	${INSTALL_DATA} ${WRKSRC}/00README ${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/00README.gatherers ${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/00DESIGN ${PREFIX}/share/doc/prngd
	${INSTALL_DATA} ${WRKSRC}/contrib/NetBSD1/prngd.conf.netbsd ${PREFIX}/share/examples/prngd
	${INSTALL_MAN} ${WRKSRC}/prngd.man ${PREFIX}/man/man1/prngd.1

.include "../../mk/bsd.pkg.mk"
