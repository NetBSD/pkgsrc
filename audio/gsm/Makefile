# $NetBSD: Makefile,v 1.9 1998/04/20 11:56:19 frueauf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp 
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	packages@netbsd.org

MAKE_FLAGS=	PREFIX="${PREFIX}"

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3

post-install:
	@strip ${PREFIX}/bin/toast
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
