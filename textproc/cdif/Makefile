# $NetBSD: Makefile,v 1.6 2001/09/09 20:36:48 agc Exp $
#

DISTNAME=		cdif-1.15
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/
EXTRACT_SUFX=		# empty

MAINTAINER=		packages@netbsd.org
COMMENT=		word context diff

LICENSE=		no-commercial-use

USE_PERL5=		# defined

WRKSRC=			${WRKDIR}
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
