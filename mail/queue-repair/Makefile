# $NetBSD: Makefile,v 1.16 2022/06/30 11:18:35 nia Exp $
#

DISTNAME=		queue-repair-0.9.0
PKGREVISION=		10
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/queue-repair/
COMMENT=		Check or correct most corruptions of the queue in qmail
LICENSE=		gnu-gpl-v2

SYMLINK3_PATCH=		queue-repair-0.9.0-symlink3-20180724.patch
PATCHFILES+=		${SYMLINK3_PATCH}
SITES.${SYMLINK3_PATCH}= https://schmonz.com/qmail/queuerepairsymlink3/

REPLACE_PYTHON=		queue_repair.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	queue_repair.py
SUBST_SED.paths=	-e "s|'/var/qmail'|'${QMAILDIR}'|g"

SUBST_CLASSES+=		users
SUBST_STAGE.users=	do-configure
SUBST_FILES.users=	queue_repair.py
SUBST_SED.users=	-e "s|'alias'|'${QMAIL_ALIAS_USER}'|g"
SUBST_SED.users+=	-e "s|'qmaild'|'${QMAIL_DAEMON_USER}'|g"
SUBST_SED.users+=	-e "s|'qmaill'|'${QMAIL_LOG_USER}'|g"
SUBST_SED.users+=	-e "s|'qmailp'|'${QMAIL_PASSWD_USER}'|g"
SUBST_SED.users+=	-e "s|'qmailq'|'${QMAIL_QUEUE_USER}'|g"
SUBST_SED.users+=	-e "s|'qmailr'|'${QMAIL_REMOTE_USER}'|g"
SUBST_SED.users+=	-e "s|'qmails'|'${QMAIL_SEND_USER}'|g"
SUBST_NOOP_OK.users=	yes

SUBST_CLASSES+=		groups
SUBST_STAGE.groups=	do-configure
SUBST_FILES.groups=	queue_repair.py
SUBST_SED.groups=	-e "s|'qmail'|'${QMAIL_QMAIL_GROUP}'|g"
SUBST_SED.groups+=	-e "s|'nofiles'|'${QMAIL_NOFILES_GROUP}'|g"
SUBST_NOOP_OK.groups=	yes

BUILD_DEFS+=		QMAILDIR QMAIL_ALIAS_USER QMAIL_DAEMON_USER
BUILD_DEFS+=		QMAIL_LOG_USER QMAIL_PASSWD_USER QMAIL_QUEUE_USER
BUILD_DEFS+=		QMAIL_REMOTE_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP QMAIL_NOFILES_GROUP

NO_BUILD=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py \
		${DESTDIR}${PREFIX}/bin/queue_repair

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
