# $NetBSD: Makefile,v 1.4 2004/04/04 22:16:59 hubertf Exp $
#

DISTNAME=	gpg2dot-1.3
WRKSRC=		${WRKDIR}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Converts your GnuPG keyring to a graph of associations

USE_LANGUAGES=	# empty
USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

DISTVER=	${DISTNAME:S/gpg2dot-//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-extract:
	${CP} ${FILESDIR}/gpg2dot.pl ${WRKSRC}/gpg2dot.pl
#	${CP} ${FILESDIR}/gpg2dot.1 ${WRKSRC}/gpg2dot.1.in

do-build:
.for FILE in gpg2dot
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${WRKSRC}/${FILE}.pl 			\
		> ${WRKSRC}/${FILE}
.endfor
#.for FILE in gpg2dot
#	${SED} -e ''					\
#		< ${WRKSRC}/${FILE}.1.in		\
#		> ${WRKSRC}/${FILE}.1
#	${NROFF} ${WRKSRC}/${FILE}.1 >${WRKSRC}/${FILE}.0
#.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpg2dot ${PREFIX}/bin/gpg2dot
#	${INSTALL_MAN} ${WRKSRC}/gpg2dot.0 ${PREFIX}/man/cat1
#	${INSTALL_MAN} ${WRKSRC}/gpg2dot.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
