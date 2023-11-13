# $NetBSD: squirrelmail.mk,v 1.1 2023/11/13 15:59:03 taca Exp $

.if !defined(_SQUIRRELMAIL_MK)
_SQUIRRELMAIL_MK=	# defined

EGDIR=			share/examples/${PHP_PKG_PREFIX}/squirrelmail
SMDIR=			share/${PHP_PKG_PREFIX}/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail

MESSAGE_SUBST+=		SMDIR=${PREFIX}/${SMDIR}
FILES_SUBST+=		SMDIR=${PREFIX}/${SMDIR}

PLIST_SUBST+=		EGDIR=${EGDIR} SMDIR=${SMDIR}

PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ { sub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${SMDIR:S|/|\\/|g}/ { sub(/${SMDIR:S|/|\\/|g}/, "$${SMDIR}") }

.endif # _SQUIRRELMAIL_MK
