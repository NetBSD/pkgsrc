# $NetBSD: Makefile,v 1.41 2025/05/03 16:08:16 vins Exp $

DISTNAME=	keychain-2.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=funtoo/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.funtoo.org/Keychain
COMMENT=	Nice ssh-agent front-end
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

USE_TOOLS+=	groff perl:build pod2man

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${DESTDIR}${PREFIX}/bin/keychain
	${INSTALL_MAN} ${WRKSRC}/keychain.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md	\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
