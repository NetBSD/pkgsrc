# $NetBSD: Makefile,v 1.16 2024/01/04 11:28:17 schmonz Exp $

DISTNAME=		swaks-20240103.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}files/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.jetmore.org/john/code/swaks/
COMMENT=		Featureful, flexible, scriptable SMTP test tool
LICENSE=		gnu-gpl-v2

#DEPENDS+=		p5-Authen-NTLM (not in pkgsrc)
DEPENDS+=		p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# none
REPLACE_PERL=		${PKGBASE}

NO_BUILD=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
