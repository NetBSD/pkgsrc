# $NetBSD: Makefile,v 1.8 2012/03/10 22:23:13 markd Exp $
#

DISTNAME=	pdfjam_2.02
PKGNAME=	${DISTNAME:C/_/-/}
CATEGORIES=	print
MASTER_SITES=	http://www.warwick.ac.uk/go/pdfjam/
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/
COMMENT=	Small collection of PDF utilities
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/pdfjam

UTILS=		pdf180 pdf270 pdf90 pdfbook pdfflip pdfjam pdfjam-pocketmod \
	pdfjam-slides3up pdfjam-slides6up pdfjoin pdfnup pdfpun

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
.for _util in ${UTILS}
		${INSTALL_SCRIPT} ${WRKSRC}/bin/${_util} ${DESTDIR}${PREFIX}/bin/${_util}
		${INSTALL_MAN} ${WRKSRC}/man1/${_util}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${_util}.1
.endfor
.undef ${_util}

.include "../../mk/bsd.pkg.mk"
