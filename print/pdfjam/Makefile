# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:43 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/pdfjam

UTILS=		pdf90 pdfjoin pdfnup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
.for _util in ${UTILS}
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/${_util} ${DESTDIR}${PREFIX}/bin/${_util}
		${INSTALL_MAN} ${WRKSRC}/man1/${_util}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${_util}.1
.endfor
.undef ${_util}

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
