# $NetBSD: Makefile,v 1.1.1.1 2000/03/12 09:44:29 itojun Exp $
#

DISTNAME=		cdif-1.15
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/
DISTFILES=		${DISTNAME}

MAINTAINER=		packages@netbsd.org

USE_PERL5=		yes

NO_WRKSUBDIR=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}.dist

# assumes perl is in ${LOCALBASE}/bin/perl
do-patch:
	${SED} -e '1s@/usr/local/bin/perl@${LOCALBASE}/bin/perl@' \
		< ${WRKSRC}/${DISTNAME}.dist > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
