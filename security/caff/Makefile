# $NetBSD: Makefile,v 1.1.1.1 2006/03/07 12:22:21 ghen Exp $

DISTNAME=	signing-party_0.4.4.orig
PKGNAME=	caff-0.4.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/signing-party/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://pgp-tools.alioth.debian.org/
COMMENT=	CA - Fire and Forget

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}/caff

USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

DEPENDS+=	gnupg>=1.3.92:../../security/gnupg
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface

SCRIPTS=	caff pgp-clean pgp-fixkey

REPLACE_PERL+=	${SCRIPTS}

do-install:
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/${script} ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/${script}.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/caff
.for doc in README README.gpg-agent README.many-keys README.v3-keys
	${INSTALL_DATA} ${WRKSRC:Q}/${doc} ${PREFIX:Q}/share/doc/caff/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/caff
	${INSTALL_DATA} ${WRKSRC:Q}/caffrc.sample ${PREFIX:Q}/share/examples/caff/

.include "../../mk/bsd.pkg.mk"
