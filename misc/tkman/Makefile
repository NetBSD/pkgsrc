# New ports collection makefile for:	tkman
# Version required:     1.8
# Date created:         27 Dec 1994
# Whom:                 thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1997/10/11 21:55:04 hubertf Exp $
#

DISTNAME=	tkman-1.8
CATEGORIES=	misc tk41
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/old/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=	"Don't sell for profit"
MAN1=		tkman.1

.include <bsd.port.mk>
