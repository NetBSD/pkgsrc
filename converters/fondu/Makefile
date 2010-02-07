# $NetBSD: Makefile,v 1.10 2010/02/07 17:12:34 zafer Exp $
#

DISTNAME=	fondu_src-060102
PKGNAME=	fondu-060102
CATEGORIES=	converters print fonts
MASTER_SITES=	http://fondu.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fondu.sourceforge.net/
COMMENT=	Utility to convert between Mac fonts and UNIX fonts
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	for f in fondu dfont2res frombin tobin showfond ufond; do	\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin; \
		${INSTALL_MAN} ${WRKSRC}/$$f.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done

.include "../../mk/bsd.pkg.mk"
