# New ports collection makefile for:	gv
# Version required:	gv-3.5.8
# Date created:		Nov 1997
# Whom:			soren@t.dk
#
# $NetBSD: Makefile,v 1.6 1998/02/11 07:29:58 hubertf Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xaw3d.6.:${PORTSDIR}/x11/Xaw3d
RUN_DEPENDS=	${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript5

USE_IMAKE=	yes

CAT1=		gv.0

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE} install.doc)
.endif
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
