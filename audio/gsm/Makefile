# New ports collection makefile for:	gsm
# Version required:     gsm-1.0.10
# Date created:		5 January 1995
# Whom:			pst
#
# $NetBSD: Makefile,v 1.4 1998/01/19 00:54:27 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp 
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

# FreeBSD maintainer
MAINTAINER=	ports@FreeBSD.org

MAKE_FLAGS=	PREFIX="${PREFIX}"

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3

post-install:
	${LDCONFIG} -m ${PREFIX}/lib || /usr/bin/true

.include <bsd.port.mk>
