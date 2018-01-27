# $NetBSD: Makefile,v 1.39 2018/01/27 10:00:15 roy Exp $

DISTVERS=	2.8.5
PKGNAME=	keychain-${DISTVERS}
CATEGORIES=	security
MASTER_SITES=	https://github.com/funtoo/keychain/archive/
DISTNAME=	${DISTVERS}
EXTRACT_SUFX=	.tar.gz
WRKSRC=		${WRKDIR}/keychain-${DISTVERS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.funtoo.org/Keychain
COMMENT=	Nice ssh-agent front-end
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
