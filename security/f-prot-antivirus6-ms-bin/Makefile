# $NetBSD: Makefile,v 1.1.1.1 2009/09/22 17:41:07 taca Exp $
#
DISTNAME=		${FP_DISTNAME}
CATEGORIES=		security

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/corporate_users/unix/
COMMENT=		F-PROT antivirus for Mail Servers

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		pax perl:run

FP_TYPE=		ms

RCD_SCRIPTS=		fpscand scanmail

BUILD_DEFS+=		VARBASE

VARDIR=			${VARBASE}/f-prot

OWN_DIRS_PERMS+=	${VARDIR} ${BINOWN} ${BINGRP} 0751 \
			${VARDIR}/backup ${BINOWN} ${BINGRP} 0700 \
			${VARDIR}/tmp ${BINOWN} ${BINGRP} 0700 \

FILES_SUBST+=		VARDIR=${VARDIR}
PLIST_SUBST+=		VARDIR=${VARDIR}

REPLACE_PERL+=		mailtools/scan-mail.pl

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Configuring default paths.
SUBST_STAGE.paths=	pre-install
SUBST_SED.paths=	${FILES_SUBST_SED}
SUBST_FILES.paths+=	mailtools/scan-mail.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 sbin ${DATADIR} ${DOCDIR}/html \
			${EGDIR} ${FPROTDIR} ${PERL5_SUB_INSTALLVENDORLIB}

do-install: install-common install-fpscand install-ms

install-ms:
	${INSTALL_SCRIPT} ${WRKSRC}/mailtools/scan-mail.pl \
		${DESTDIR}${PREFIX}/${FPROTDIR}
	${CHMOD} 0750  ${DESTDIR}${PREFIX}/${FPROTDIR}/scan-mail.pl
	cd ${WRKSRC}/mailtools; \
		${INSTALL_PROGRAM} fp-milter fp-qmail \
			${DESTDIR}${PREFIX}/${FPROTDIR}
	cd ${WRKSRC}/doc/man/; \
		${INSTALL_MAN} scan-mail.pl.8 fp-milter.8 fp-qmail.8 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${FIND} ${WRKSRC}/perl -type f -exec ${CHMOD} 0444 {} \; \
			-name '*.orig' -exec rm -f {} \;
	cd ${WRKSRC}/perl/lib; pax -rw . ${DESTDIR}${PERL5_INSTALLVENDORLIB}

.include "../../security/f-prot-antivirus6/Makefile.common"
.include "../../mk/bsd.pkg.mk"
