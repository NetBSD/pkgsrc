# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:30 jlam Exp $
#

DISTNAME=	if-psprint-1.7
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.mono.org/abs/tools/if-psprint/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/if-psprint/
COMMENT=	Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

USE_PERL5=	YES

INSTALLATION_DIRS=	libexec man/man1

do-build:
	${SED} -e 's|/usr/local|${PREFIX}|g'		\
		< ${WRKSRC}/if-psprint.pl		\
		> ${WRKSRC}/if-psprint
	pod2man ${WRKSRC}/if-psprint > ${WRKSRC}/if-psprint.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/if-psprint ${PREFIX}/libexec/if-psprint
	${INSTALL_MAN} ${WRKSRC}/if-psprint.1 ${PREFIX}/man/man1/if-psprint.1

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
