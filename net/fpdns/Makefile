# $NetBSD: Makefile,v 1.2 2010/02/11 20:53:48 joerg Exp $
#

DISTNAME=	fpdns-0.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.rfc.se/fpdns/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rfc.se/fpdns/
COMMENT=	Fingerprinting DNS servers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

WRKSRC=		${WRKDIR}
REPLACE_PERL=	fpdns.pl
USE_TOOLS+=	perl
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fpdns.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpdns.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
