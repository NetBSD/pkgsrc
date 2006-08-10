# $NetBSD: Makefile,v 1.1.1.1 2006/08/10 11:18:16 abs Exp $
#

DISTNAME=	imapsync-1.182
CATEGORIES=	mail
MASTER_SITES=	http://www.linux-france.org/prj/imapsync/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.linux-france.org/prj/imapsync/dist/
COMMENT=	Incremental recursive IMAP transfer tool

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mail-IMAPClient>=2.2.9:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL+=	imapsync

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapsync ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/imapsync

.include "../../mk/bsd.pkg.mk"
