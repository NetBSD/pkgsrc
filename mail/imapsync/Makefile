# $NetBSD: Makefile,v 1.12 2013/12/09 14:17:48 obache Exp $

DISTNAME=	imapsync-1.564
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://fedorahosted.org/released/imapsync/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/imapsync/
COMMENT=	Incremental recursive IMAP transfer tool

DEPENDS+=	p5-Data-Uniqid>=0:../../devel/p5-Data-Uniqid
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mail-IMAPClient>=3.1.9:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

FETCH_USING=	curl
NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL+=	imapsync

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapsync ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/imapsync

.include "../../mk/bsd.pkg.mk"
