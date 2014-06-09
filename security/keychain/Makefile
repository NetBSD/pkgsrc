# $NetBSD: Makefile,v 1.30 2014/06/09 10:30:20 fhajny Exp $

DISTNAME=	keychain-2.7.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.funtoo.org/index.php?title=Keychain
COMMENT=	Nice ssh-agent front-end
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		bash:run
NO_BUILD=		yes

REPLACE_BASH+=		keychain

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.rst \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
