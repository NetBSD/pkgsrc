# $NetBSD: Makefile,v 1.2 2004/01/03 05:05:15 ben Exp $
#

DISTNAME=		fp-netbsd-ws-4.3.1
WRKSRC=			${WRKDIR}/f-prot
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.f-prot.com/pub/bsd/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/home_use/bsd/
COMMENT=		F-prot antivirus for home users

DEPENDS+=		p5-libwww>=5.69:../../www/p5-libwww

ONLY_FOR_PLATFORM=	NetBSD-*-i386
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
LICENSE=		fp-netbsd-ws-license

NO_BUILD=		yes
USE_BUILDLINK2=		yes

post-patch:
	cd ${WRKSRC}/tools && ${MV} check-updates.pl check-updates.pl.bak
	${SED} -e "s,/usr/local/f-prot,${PREFIX}/lib/fp-netbsd-ws,g" \
		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"\
		<${WRKSRC}/tools/check-updates.pl.bak \
		>${WRKSRC}/tools/check-updates.pl
	${MV} ${WRKSRC}/f-prot.sh ${WRKSRC}/f-prot.sh.bak
	${SED} -e "s,/usr/local/f-prot,${PREFIX}/lib/fp-netbsd-ws," \
		<${WRKSRC}/f-prot.sh.bak \
		>${WRKSRC}/f-prot.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f-prot.sh ${PREFIX}/bin/f-prot
	${INSTALL_SCRIPT} ${WRKSRC}/tools/check-updates.pl ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man_pages/check-updates.pl.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man_pages/f-prot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/lib/fp-netbsd-ws
	${INSTALL_DATA} ${WRKSRC}/*.DEF ${PREFIX}/lib/fp-netbsd-ws
	${INSTALL_DATA} ${WRKSRC}/ENGLISH.TX0 ${PREFIX}/lib/fp-netbsd-ws
	${INSTALL_PROGRAM} ${WRKSRC}/f-prot ${PREFIX}/lib/fp-netbsd-ws
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fp-netbsd-ws
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/CHANGES \
		${PREFIX}/share/doc/fp-netbsd-ws
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/fp-netbsd-ws
	${INSTALL_DATA} ${WRKSRC}/doc_ws/* ${PREFIX}/share/doc/html/fp-netbsd-ws

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
