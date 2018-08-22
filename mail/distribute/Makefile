# $NetBSD: Makefile,v 1.33 2018/08/22 09:45:24 wiz Exp $

DISTNAME=	distribute-2.1-pl19
PKGNAME=	distribute-2.1.26
PKGREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/network/mail/distribute/
# AWOL

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/network/mail/distribute/BETA/
PATCHFILES=	patch.20.gz patch.21e.gz patch.22e.gz patch.23e.gz \
		patch.24e.gz patch.25e.gz patch.26e.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
# in japanese
# HOMEPAGE=	http://www.foretune.co.jp/people/shigeya/distribute/
# AWOL
COMMENT=	Mail dispatcher for mailing list.  Fits nicely with majordomo

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/distribute-pl19
USE_TOOLS+=	perl:run

MAN1=		distribute.1
DIST_SUBDIR=	distribute
PATCH_DIST_STRIP=	-p1

# customize below if you would like to
# this needs to be the same as majordomo uses
MAJORDOMO_HOMEDIR?=	${VARBASE}/majordomo
MAJORDOMO_LIST_DIR=	${MAJORDOMO_HOMEDIR}/lists
# just as example, you may disagree with these
MAILINGLIST_DIR=	/var/mail-list
ARCHIVE_DIR=		/var/spool/mail-list
DEF_DOMAINNAME?=	your.domain.here

MAKE_ENV+=	DEFAULTCONFIG='-DDEF_SEQ_PATH="\"${MAILINGLIST_DIR}\"" \
			-DDEF_RECIPIENT_PATH="\"${MAILINGLIST_DIR}\"" \
			-DDEF_MAJORDOMO_RECIPIENT_PATH="\"${MAJORDOMO_LIST_DIR}\"" \
			-DDEF_DOMAINNAME="\"${DEF_DOMAINNAME}\"" \
			-DDEF_ARCHIVE_PATH="\"${ARCHIVE_DIR}\""' \
		INSTALL=${INSTALL:Q} \
		INSTALL_MAN=${INSTALL_MAN:Q}

pre-build:
	${TOUCH} ${WRKSRC}/logging.h ${WRKSRC}/strsep.c

post-build: mmessage
post-install: mmessage
mmessage::
	@${ECHO} "===> distribute was compiled with the following configuration:"
	@${ECHO} "     membership file directory: ${MAILINGLIST_DIR}"
	@${ECHO} "     membership file directory: ${MAJORDOMO_LIST_DIR} (for majordomo)"
	@${ECHO} "     archiving directory: ${ARCHIVE_DIR}"
	@${ECHO} "     if necessary, override them and perform compilation again."
	@${ECHO} "     there's no way to override them at runtime."

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
