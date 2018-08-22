# $NetBSD: Makefile,v 1.22 2018/08/22 09:46:18 wiz Exp $

DISTNAME=	gpg2dot-1.5
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Converts your GnuPG keyring to a graph of associations

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
.for file in gpg2dot
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${WRKSRC}/${file}.pl 			\
		> ${WRKSRC}/${file}
.endfor
#.for file in gpg2dot
#	${SED} -e ''					\
#		< ${WRKSRC}/${file}.1.in		\
#		> ${WRKSRC}/${file}.1
#.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpg2dot ${DESTDIR}${PREFIX}/bin/gpg2dot
#	${INSTALL_MAN} ${WRKSRC}/gpg2dot.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
