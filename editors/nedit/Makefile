# $NetBSD: Makefile,v 1.61 2024/11/22 17:07:09 gutteridge Exp $

DISTNAME=	nedit-5.7-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=nedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif-based standard GUI style text editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl

MAKE_JOBS_SAFE=	no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=		netbsd docs
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PREFIX}/share/doc/nedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/nedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/nc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/nedit.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/nc.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nedit-nc.1
.for f in README ReleaseNotes
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/nedit
.endfor
.for f in faq.txt NEdit.ad
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/nedit
.endfor

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
