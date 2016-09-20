# $NetBSD: Makefile,v 1.35 2016/09/20 12:36:09 mef Exp $

DISTNAME=	keychain-2.8.3
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.funtoo.org/Keychain
COMMENT=	Nice ssh-agent front-end
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

NO_BUILD=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
