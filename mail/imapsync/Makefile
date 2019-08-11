# $NetBSD: Makefile,v 1.22 2019/08/11 13:21:28 wiz Exp $

DISTNAME=	imapsync-1.607
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	https://releases.pagure.org/imapsync/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://pagure.io/imapsync
COMMENT=	Incremental recursive IMAP transfer tool
LICENSE=	public-domain

DEPENDS+=	p5-Data-Uniqid>=0:../../devel/p5-Data-Uniqid
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-Tee-[0-9]*:../../devel/p5-IO-Tee
DEPENDS+=	p5-Mail-IMAPClient>=3.1.9:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Term-ReadKey>=0:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL+=	imapsync

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapsync ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/imapsync

.include "../../mk/bsd.pkg.mk"
