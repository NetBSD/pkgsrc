# $NetBSD: Makefile,v 1.16 2017/08/16 20:45:31 wiz Exp $
#

DISTNAME=		lcab-1.0b12
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_FREEBSD}

#HOMEPAGE=		http://ohnopub.net/~ohnobinki/lcab
COMMENT=		Microsoft cabinet (.CAB) file creator
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
