# New ports collection makefile for:	crashme
# Version required:     		2.4
# Date created:				Fri Nov 14 08:39:08 GMT 1997
# Whom:					Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.2 1998/01/24 23:29:30 hubertf Exp $
#

DISTNAME=       	crashme-2.4
CATEGORIES=		devel
MASTER_SITES=   	http://ochimizu-www.jaist.ac.jp:8000/linux/vger/crashme/
EXTRACT_SUFX=		-shar

MAINTAINER=		agc@netbsd.org

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
MAKEFILE=		makefile

MAN1=			crashme.1

.include <bsd.port.mk>
