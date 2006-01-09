# $NetBSD: Makefile,v 1.1.1.1 2006/01/09 10:10:08 uebayasi Exp $
#

PKGNAME=	${DISTFILES:C/_/-/}
DISTNAME=	pdfjam_1.20
CATEGORIES=	print
MASTER_SITES=	http://www.warwick.ac.uk/go/pdfjam/
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/
COMMENT=	Small collection of PDF utilities

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/pdfjam

UTILS=		pdf90 pdfjoin pdfnup

do-install:
.for _util in ${UTILS}
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/${_util} ${PREFIX}/bin/${_util}
		${INSTALL_MAN} ${WRKSRC}/man1/${_util}.1 ${PREFIX}/man/man1/${_util}.1
.endfor
.undef ${_util}

.include "../../mk/bsd.pkg.mk"
