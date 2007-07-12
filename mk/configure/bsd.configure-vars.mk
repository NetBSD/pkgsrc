# $NetBSD: bsd.configure-vars.mk,v 1.4 2007/07/12 18:59:15 jlam Exp $
#
# CONFIGURE_DIRS is the list of directories in which to run the
#	configure process.  If the directories are relative paths,
#	then they are assumed to be relative to ${WRKSRC}.
#
# SCRIPTS_ENV is the shell environment passed to xmkmf (used by
#	the configure process).
#
CONFIGURE_DIRS?=	${WRKSRC}
SCRIPTS_ENV?=		# empty

SCRIPTS_ENV+=	${ALL_ENV}
SCRIPTS_ENV+=	_PKGSRCDIR=${_PKGSRCDIR}
SCRIPTS_ENV+=	${BATCH:DBATCH=yes}
SCRIPTS_ENV+=	CURDIR=${.CURDIR}
SCRIPTS_ENV+=	DEPENDS=${DEPENDS:Q}
SCRIPTS_ENV+=	DISTDIR=${DISTDIR}
SCRIPTS_ENV+=	FILESDIR=${FILESDIR}
SCRIPTS_ENV+=	LOCALBASE=${LOCALBASE}
SCRIPTS_ENV+=	PATCHDIR=${PATCHDIR}
SCRIPTS_ENV+=	PKGSRCDIR=${PKGSRCDIR}
SCRIPTS_ENV+=	SCRIPTDIR=${SCRIPTDIR}
SCRIPTS_ENV+=	VIEWBASE=${VIEWBASE}
SCRIPTS_ENV+=	WRKDIR=${WRKDIR}
SCRIPTS_ENV+=	WRKSRC=${WRKSRC}
SCRIPTS_ENV+=	X11BASE=${X11BASE}
