# $NetBSD: Makefile,v 1.7 2015/09/06 12:08:06 wiedi Exp $
#

DISTNAME=		hping3-alpha-2
PKGNAME=		hping3-3a2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://wiki.hping.org/uploadedfiles/101/

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://wiki.hping.org/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer
LICENSE=		gnu-gpl-v2 AND original-bsd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/configure
SUBST_FILES.paths+=	${WRKSRC}/Makefile.in
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'

USE_TOOLS=		gmake
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ENV+=		INSTALL_MANPATH=${PKGMANDIR}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
