# $NetBSD: Makefile,v 1.6 2006/08/16 09:53:49 tonio Exp $

DISTNAME=	signing-party_0.4.7.orig
PKGNAME=	caff-0.4.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/signing-party/}

MAINTAINER=	ghen@NetBSD.org,tonio@NetBSD.org
HOMEPAGE=	http://pgp-tools.alioth.debian.org/
COMMENT=	Various GnuPG related tools

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}

USE_TOOLS+=	gmake pod2man
USE_TOOLS+=	perl:run

DEPENDS+=	gnupg>=1.3.92:../../security/gnupg
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface
DEPENDS+=	dialog>=1.0:../../misc/dialog

REPLACE_PERL+=	caff/caff caff/pgp-fixkey caff/pgp-clean \
		gpg-key2ps/gpg-key2ps gpgsigs/gpgsigs \
		gpglist/gpglist keylookup/keylookup

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	caff/caff keylookup/keylookup.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/caff/caff ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-fixkey ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-clean ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-key2ps/gpg-key2ps ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpgsigs/gpgsigs ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpglist/gpglist ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/keylookup/keylookup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/caff/caff.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-fixkey.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-clean.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-key2ps/gpg-key2ps.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpgsigs/gpgsigs.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpglist/gpglist.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/keylookup/keylookup.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README ${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README.many-keys ${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README.gpg-agent ${PREFIX}/share/doc/caff
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC}/caff/caffrc.sample ${PREFIX}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC}/gpgsigs/gpgsigs-lt2k5.txt ${PREFIX}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC}/gpgsigs/gpgsigs-lt2k5-annotated.txt ${PREFIX}/share/examples/caff

.include "../../mk/bsd.pkg.mk"
