# $NetBSD: Makefile,v 1.1.1.1 2003/08/15 11:18:46 wiz Exp $
#

DISTNAME=		YoSucker-pr37
PKGNAME=		${DISTNAME:S/pr//}
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yosucker/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://yosucker.sourceforge.net/
COMMENT=		Download mails from Yahoo webmail into mbox

DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_PERL5=		# defined
REPLACE_PERL=		bin/EncProxyPasswd bin/EncPasswd bin/YoSucker

NO_BUILD=		# defined

EGDIR=			${PREFIX}/share/examples/YoSucker
DOCDIR=			${PREFIX}/share/doc/YoSucker

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/* ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
