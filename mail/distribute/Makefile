# $NetBSD: Makefile,v 1.8 2002/07/02 10:55:22 wiz Exp $
# FreeBSD: ports/mail/distribute/Makefile,v 1.2 1999/08/25 06:50:06 obrien Exp
#

DISTNAME=	distribute-2.1-pl19
PKGNAME=	distribute-2.1.26
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/network/mail/distribute/

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/network/mail/distribute/BETA/
PATCHFILES=	patch.20.gz patch.21e.gz patch.22e.gz patch.23e.gz \
		patch.24e.gz patch.25e.gz patch.26e.gz

MAINTAINER=	itojun@itojun.org
# in japanese
HOMEPAGE=	http://www.foretune.co.jp/distribute/
COMMENT=	Mail dispatcher for mailing list.  Fits nicely with majordomo

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/distribute-pl19
MAN1=		distribute.1
DIST_SUBDIR=	distribute
# Compile time configuration required.
IS_INTERACTIVE=	YES

# customize below if you would like to
# mail/majordomo likes this
MAJORDOMO_DIR=		/home/majordom
MAJORDOMO_LIST_DIR=	${MAJORDOMO_DIR}/lists
# just as example, you may disagree with these
MAILINGLIST_DIR=	/var/mail-list
ARCHIVE_DIR=		/var/spool/mail-list
DEF_DOMAINNAME?=	your.domain.here

MAKE_ENV+=	DEFAULTCONFIG="-DDEF_SEQ_PATH=\\\"${MAILINGLIST_DIR}\\\" \
			-DDEF_RECIPIENT_PATH=\\\"${MAILINGLIST_DIR}\\\" \
			-DDEF_MAJORDOMO_RECIPIENT_PATH=\\\"${MAJORDOMO_LIST_DIR}\\\" \
			-DDEF_DOMAINNAME=\\\"${DEF_DOMAINNAME}\\\" \
			-DDEF_ARCHIVE_PATH=\\\"${ARCHIVE_DIR}\\\"" \
		INSTALL="${INSTALL}" \
		INSTALL_MAN="${INSTALL_MAN}"

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

.include "../../mk/bsd.pkg.mk"
