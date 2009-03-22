# $NetBSD: Makefile,v 1.9 2009/03/22 04:53:38 manu Exp $
#

DISTNAME=	fondu_src-030428
PKGNAME=	fondu-030428
CATEGORIES=	converters print fonts
MASTER_SITES=	http://fondu.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fondu.sourceforge.net/
COMMENT=	Utility to convert between Mac fonts and UNIX fonts

WRKSRC=		${WRKDIR}/fondu
GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	for f in fondu dfont2res frombin tobin showfond ufond; do	\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin; \
		${INSTALL_MAN} ${WRKSRC}/$$f.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done

.include "../../mk/bsd.pkg.mk"
