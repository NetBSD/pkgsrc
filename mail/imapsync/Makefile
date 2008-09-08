# $NetBSD: Makefile,v 1.5 2008/09/08 22:25:13 abs Exp $
#

DISTNAME=	imapsync-1.264
CATEGORIES=	mail
MASTER_SITES=	http://www.linux-france.org/prj/imapsync/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.linux-france.org/prj/imapsync/
COMMENT=	Incremental recursive IMAP transfer tool

# Mail-IMAPClient-3.x (at least as of 3.08) has SSL regressions which make
# it not usable for imapsync, hence we have a p5-Mail-IMAPClient2 package

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mail-IMAPClient2>=2.2.9:../../mail/p5-Mail-IMAPClient2
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL+=	imapsync

INSTALLATION_DIRS=	bin share/doc

SUBST_CLASSES+=         conf
SUBST_STAGE.conf=       pre-configure
SUBST_FILES.conf=	imapsync
SUBST_SED.conf=         -e "s:IMAPClient:IMAPClient2:g"
SUBST_MESSAGE.conf=     Replacing IMAPClient with IMAPClient2

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapsync ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/imapsync

.include "../../mk/bsd.pkg.mk"
