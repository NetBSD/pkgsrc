# $NetBSD: Makefile,v 1.22 2019/08/11 13:22:44 wiz Exp $
#

DISTNAME=		yup-r1-rel
PKGNAME=		yup-1.0
PKGREVISION=		7
CATEGORIES=		print
MASTER_SITES=		# http://redback.spyda.net/~mjch/yup/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Print multiple PostScript/ASCII pages per sheet

USE_TOOLS+=		perl:run

WRKSRC=			${WRKDIR}/yup-r1
NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
