# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:22 wiz Exp $
#

DISTNAME=		YoSucker-pr37
PKGNAME=		${DISTNAME:S/pr//}
PKGREVISION=		8
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yosucker/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://yosucker.sourceforge.net/
COMMENT=		Download mails from Yahoo webmail into mbox

DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=		p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_TOOLS+=		perl:run
REPLACE_PERL=		bin/EncProxyPasswd bin/EncPasswd bin/YoSucker

NO_BUILD=		yes

EGDIR=			${PREFIX}/share/examples/YoSucker
DOCDIR=			${PREFIX}/share/doc/YoSucker
INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/* ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
