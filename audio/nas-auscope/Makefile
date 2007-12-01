# $NetBSD: Makefile,v 1.5 2007/12/01 23:47:31 wiz Exp $

DISTNAME=	nas-1.9.src
PKGNAME=	nas-auscope-1.9
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System Protocol Filter

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}/clients/audio/auscope
USE_TOOLS+=	perl:run
REPLACE_PERL=   auscope

NO_BUILD=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/auscope ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/auscope.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/auscope.1

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
