# $NetBSD: Makefile,v 1.52 2019/08/11 13:22:45 wiz Exp $

VERSION=	2.10
DISTNAME=	signing-party_${VERSION}.orig
PKGNAME=	caff-${VERSION}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/signing-party/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://pgp-tools.alioth.debian.org/
COMMENT=	Various GnuPG related tools
LICENSE=	gnu-gpl-v2 AND modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}

USE_TOOLS+=	autoconf automake gmake pod2man gsed
USE_TOOLS+=	perl:run

DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-Net-IDN-Encode-[0-9]*:../../textproc/p5-Net-IDN-Encode
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/caff share/examples/caff

.include "options.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/caff/caff ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-fixkey ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-clean ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-key2ps/gpg-key2ps ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpgsigs/gpgsigs ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpglist/gpglist ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/keylookup/keylookup ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/caff/caff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-fixkey.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-clean.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-key2ps/gpg-key2ps.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpgsigs/gpgsigs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpglist/gpglist.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/keylookup/keylookup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/caff/README ${DESTDIR}${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README.many-keys ${DESTDIR}${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README.gpg-agent ${DESTDIR}${PREFIX}/share/doc/caff
	${INSTALL_DATA} ${WRKSRC}/caff/caffrc.sample ${DESTDIR}${PREFIX}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC}/gpgsigs/gpgsigs-lt2k5.txt ${DESTDIR}${PREFIX}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC}/gpgsigs/gpgsigs-lt2k5-annotated.txt ${DESTDIR}${PREFIX}/share/examples/caff

.include "../../mk/bsd.pkg.mk"
