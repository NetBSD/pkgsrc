# $NetBSD: Makefile,v 1.12 2023/12/19 17:26:09 zafer Exp $
#

DISTNAME=		sux-1.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Set user id, preserving shell and environment, checking ssh agent

DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		sshsh-[0-9]*:../../sysutils/sshsh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX}

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-extract
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,/man/,/${PKGMANDIR}/,'

.include "../../mk/bsd.pkg.mk"
