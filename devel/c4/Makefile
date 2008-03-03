# $NetBSD: Makefile,v 1.10 2008/03/03 17:45:34 jlam Exp $
#

DISTNAME=	c4
PKGNAME=	${DISTNAME}-1.6
CATEGORIES=	devel scm
MASTER_SITES=	ftp://ftp.perforce.com/perforce/utils/c4/

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	CVS-like frontend to Perforce

DEPENDS+=	p4-[0-9]*:../../devel/p4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=	c4

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
