# $NetBSD: Makefile,v 1.3 2018/11/05 18:22:11 schmonz Exp $

DISTNAME=		swaks-20181104.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}files/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.jetmore.org/john/code/swaks/
COMMENT=		Featureful, flexible, scriptable SMTP test tool
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
#DEPENDS+=		p5-Authen-NTLM (not in pkgsrc)
DEPENDS+=		p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-Time-Local-[0-9]*:../../time/p5-Time-Local

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# none
REPLACE_PERL=		${PKGBASE}

NO_BUILD=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
