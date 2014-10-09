# $NetBSD: Makefile,v 1.14 2014/10/09 14:05:52 wiz Exp $
#

DISTNAME=		lcab-1.0b12
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_FREEBSD}

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://ohnopub.net/~ohnobinki/lcab
COMMENT=		Microsoft cabinet (.CAB) file creator

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
