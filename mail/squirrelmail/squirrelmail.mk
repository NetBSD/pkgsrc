# $NetBSD: squirrelmail.mk,v 1.3 2025/02/08 03:44:48 taca Exp $

.if !defined(SQUIRRELMAIL_MK)
SQUIRRELMAIL_MK=	# defined

EGDIR=			${PHP_EGDIR}/squirrelmail
SMDIR=			${PHP_SHAREDIR}/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail

MESSAGE_SUBST+=		SMDIR=${PREFIX}/${SMDIR}
FILES_SUBST+=		SMDIR=${PREFIX}/${SMDIR}

PLIST_SUBST+=		EGDIR=${EGDIR} SMDIR=${SMDIR}

PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ { sub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${SMDIR:S|/|\\/|g}/ { sub(/${SMDIR:S|/|\\/|g}/, "$${SMDIR}") }

.endif # SQUIRRELMAIL_MK
