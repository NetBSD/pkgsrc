# $NetBSD: squirrelmail.mk,v 1.2 2024/09/18 14:25:50 taca Exp $

.if !defined(SQUIRRELMAIL_MK)
SQUIRRELMAIL_MK=	# defined

EGDIR=			share/examples/${PHP_PKG_PREFIX}/squirrelmail
SMDIR=			share/${PHP_PKG_PREFIX}/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail

MESSAGE_SUBST+=		SMDIR=${PREFIX}/${SMDIR}
FILES_SUBST+=		SMDIR=${PREFIX}/${SMDIR}

PLIST_SUBST+=		EGDIR=${EGDIR} SMDIR=${SMDIR}

PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ { sub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${SMDIR:S|/|\\/|g}/ { sub(/${SMDIR:S|/|\\/|g}/, "$${SMDIR}") }

.endif # SQUIRRELMAIL_MK
