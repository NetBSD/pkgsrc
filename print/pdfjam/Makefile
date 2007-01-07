# $NetBSD: Makefile,v 1.5 2007/01/07 09:14:09 rillig Exp $
#

DISTNAME=	pdfjam_1.20
PKGNAME=	${DISTNAME:C/_/-/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.warwick.ac.uk/go/pdfjam/
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/
COMMENT=	Small collection of PDF utilities

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/pdfjam

UTILS=		pdf90 pdfjoin pdfnup

do-install:
.for _util in ${UTILS}
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/${_util} ${PREFIX}/bin/${_util}
		${INSTALL_MAN} ${WRKSRC}/man1/${_util}.1 ${PREFIX}/${PKGMANDIR}/man1/${_util}.1
.endfor
.undef ${_util}

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
