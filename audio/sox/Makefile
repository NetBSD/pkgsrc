# New ports collection makefile for:	sox - Sound Exchange
# Version required:	12p12
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1997/10/28 23:19:03 augustss Exp $
#

DISTNAME=	soxgamma
PKGNAME=	sox-12.12
CATEGORIES=	audio
MASTER_SITES=	http://www.spies.com/Sox/Archive/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=		yes
MAKEFILE=	Makefile.unx
MAN1=		sox.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sox ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/sox.man ${PREFIX}/man/man1/sox.1

.include <bsd.port.mk>
