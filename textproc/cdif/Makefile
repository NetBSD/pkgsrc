# $NetBSD: Makefile,v 1.3 2000/08/27 02:46:07 jlam Exp $
#

DISTNAME=		cdif-1.15
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/
EXTRACT_SUFX=		# empty

MAINTAINER=		packages@netbsd.org

USE_PERL5=		# defined

NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}.dist

do-patch:
	${SED} -e '1s@/usr/local/bin/perl@${PERL5}@' \
		< ${WRKSRC}/${DISTNAME}.dist > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
