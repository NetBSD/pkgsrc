# $NetBSD: Makefile,v 1.7 2013/03/14 16:35:32 taca Exp $
#
DISTNAME=		${FP_DISTNAME}
CATEGORIES=		security

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/corporate_users/unix/
COMMENT=		F-PROT antivirus for Mail Servers

USE_TOOLS+=		pax perl:run

FP_TYPE=		ms

RCD_SCRIPTS=		fpscand scanmail

BUILD_DEFS+=		FPROT_GROUP FPROT_USER VARBASE

VARDIR=			${VARBASE}/f-prot

OWN_DIRS_PERMS+=	${VARDIR} ${BINOWN} ${BINGRP} 0775 \
			${VARDIR}/backup ${BINOWN} ${FPROT_GROUP} 0770 \
			${VARDIR}/run ${BINOWN} ${FPROT_GROUP} 0770 \
			${VARDIR}/tmp ${BINOWN} ${FPROT_GROUP} 0770 \

FILES_SUBST+=		FPROT_USER=${FPROT_USER} VARDIR=${VARDIR}
PLIST_SUBST+=		VARDIR=${VARDIR}

SPECIAL_PERMS+=		${FPROTDIR}/scan-mail.pl ${BINOWN} ${FPROT_GROUP} 0750

PKG_GROUP=		${FPROT_GROUP}
PKG_USERS=		${FPROT_USER}

REPLACE_PERL+=		mailtools/scan-mail.pl perl/lib/Anomy/HTMLCleaner.pm \
			perl/lib/Anomy/Log.pm perl/lib/Anomy/MIMEStream.pm \
			perl/lib/Anomy/Sanitizer/FProt/Client.pm \
			perl/lib/Anomy/Sanitizer/FileTypes.pm \
			perl/lib/Anomy/Sanitizer.pm

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Configuring default paths.
SUBST_STAGE.paths=	pre-install
SUBST_SED.paths=	${FILES_SUBST_SED}
SUBST_FILES.paths+=	mailtools/scan-mail.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 sbin ${DATADIR} ${DOCDIR}/html \
			${EGDIR} ${FPROTDIR} ${PERL5_SUB_INSTALLVENDORLIB}

.include "../../mk/bsd.prefs.mk"

FPROT_GROUP?=		f-prot
FPROT_USER?=		f-prot

do-install: install-common install-fpscand install-ms

install-ms:
	${INSTALL_SCRIPT} ${WRKSRC}/mailtools/scan-mail.pl \
		${DESTDIR}${PREFIX}/${FPROTDIR}
	${CHMOD} 0750  ${DESTDIR}${PREFIX}/${FPROTDIR}/scan-mail.pl
	cd ${WRKSRC}/mailtools; \
		${INSTALL_PROGRAM} fp-milter fp-qmail \
			${DESTDIR}${PREFIX}/${FPROTDIR}
	cd ${WRKSRC}/doc/man/; \
		${INSTALL_MAN} scan-mail.pl.8 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${FIND} ${WRKSRC}/perl -type f -exec ${CHMOD} 0444 {} \; \
			-name '*.orig' -exec rm -f {} \;
	cd ${WRKSRC}/perl/lib; pax -rw . ${DESTDIR}${PERL5_INSTALLVENDORLIB}

.include "../../security/f-prot-antivirus6/Makefile.common"
.include "../../mk/bsd.pkg.mk"
