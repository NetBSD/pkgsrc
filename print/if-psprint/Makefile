# $NetBSD: Makefile,v 1.10 2002/04/16 11:52:24 abs Exp $
#

DISTNAME=	if-psprint-1.5
CATEGORIES=	print
MASTER_SITES=	http://www.mono.org/abs/tools/if-psprint/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.mono.org/abs/tools/if-psprint/
COMMENT=	Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	enscript-[0-9]*:../../print/enscript

USE_PERL5=	YES

do-build:
	${SED} -e 's|/usr/local|${PREFIX}|g'		\
		< ${WRKSRC}/if-psprint.pl		\
		> ${WRKSRC}/if-psprint
	pod2man ${WRKSRC}/if-psprint > ${WRKSRC}/if-psprint.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/if-psprint ${PREFIX}/libexec/if-psprint
	${INSTALL_MAN} ${WRKSRC}/if-psprint.1 ${PREFIX}/man/man1/if-psprint.1

.include "../../mk/bsd.pkg.mk"
