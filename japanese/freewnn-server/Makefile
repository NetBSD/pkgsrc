# $NetBSD: Makefile,v 1.2 1999/09/03 04:31:45 sakamoto Exp $
#

PKGNAME=	ja-FreeWnn-server-1.10
CATEGORIES=	japanese
DEPENDS+=	ja-FreeWnn-lib-1.10:../../japanese/freewnn-lib

WNNDIR=		Wnn
WNN_TARGET=	SERVER
WNN_LANG=	ja_JP

MASTERDIR=	${.CURDIR}/../../misc/freewnn-common
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/patches

STARTUP_SCRIPT=	etc/rc.d/ja-freewnn.sh
JSERVER=	${PREFIX}/sbin/jserver
SCTITLE=	ja-FreeWnn

.include "${MASTERDIR}/Makefile"
