# $NetBSD: Makefile,v 1.13 2011/01/13 00:40:31 lukem Exp $
#

DISTNAME=	gpg2dot-1.5
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Converts your GnuPG keyring to a graph of associations

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

NO_CONFIGURE=	yes

DISTVER=	${DISTNAME:S/gpg2dot-//}
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

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
#.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpg2dot ${DESTDIR}${PREFIX}/bin/gpg2dot
#	${INSTALL_MAN} ${WRKSRC}/gpg2dot.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
