# $NetBSD: Makefile,v 1.8 2001/09/09 20:36:44 agc Exp $
#

DISTNAME=		if-psprint-1.4
CATEGORIES=		print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		abs@netbsd.org
COMMENT=		Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	enscript-[0-9]*:../../print/enscript

USE_PERL5=		YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		< ${FILESDIR}/if-psprint.pl		\
		> ${WRKSRC}/if-psprint
	pod2man ${WRKSRC}/if-psprint > ${WRKSRC}/if-psprint.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/if-psprint ${PREFIX}/libexec/if-psprint
	${INSTALL_MAN} ${WRKSRC}/if-psprint.1 ${PREFIX}/man/man1/if-psprint.1

.include "../../mk/bsd.pkg.mk"
