# $NetBSD: Makefile,v 1.15 2005/03/17 12:44:42 salo Exp $
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
