# $NetBSD: Makefile,v 1.40 2018/04/18 19:25:27 kamil Exp $

DISTNAME=	keychain-2.8.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=funtoo/}

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
