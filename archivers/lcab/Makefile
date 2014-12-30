# $NetBSD: Makefile,v 1.15 2014/12/30 08:18:52 plunky Exp $
#

DISTNAME=		lcab-1.0b12
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_FREEBSD}

HOMEPAGE=		http://ohnopub.net/~ohnobinki/lcab
COMMENT=		Microsoft cabinet (.CAB) file creator
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
