# $NetBSD: Makefile,v 1.22 2009/06/08 09:15:08 wiz Exp $
#

DISTNAME=	clive-2.1.13
CATEGORIES=	net multimedia www
MASTER_SITES=	http://clive.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts
# similar, but not exact wording
#LICENSE=	mit

DEPENDS+=	p5-BerkeleyDB>=0.34:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-Clipboard>=0.09:../../x11/p5-Clipboard
DEPENDS+=	p5-Config-Tiny>=2.12:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-Expect>=1.21:../../devel/p5-Expect
DEPENDS+=	p5-HTML-Parser>=2.37:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-Pager>=0.05:../../devel/p5-IO-Pager
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI
DEPENDS+=	p5-WWW-Curl>=4.05:../../www/p5-WWW-Curl

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clive ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/clive.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
