# $NetBSD: Makefile,v 1.14 2025/03/03 21:32:26 nia Exp $
#

DISTNAME=		gnu-crypto-2.0.1-bin
PKGNAME=		${DISTNAME:S/-bin$//}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GNUPG:=gnu-crypto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/gnu-crypto/
COMMENT=		GPL implementation of the Java Crypto Extensions

USE_JAVA2=		yes
INSTALLATION_DIRS=	lib/java/gnu-crypto ${PKGINFODIR}

NO_BUILD=	yes
INFO_FILES=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/gnu-crypto/
	${INSTALL_MAN} ${WRKSRC}/docs/*.info* ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
