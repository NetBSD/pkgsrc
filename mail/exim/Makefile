# $NetBSD: Makefile,v 1.1 1999/09/07 13:22:50 ad Exp $

DISTNAME=	exim-3.03
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/ \
		ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/

DEPENDS+=	perl-5.00404:../../lang/perl5

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${WRKSRC}/Local/Makefile.netbsd \
	    > ${WRKSRC}/Local/Makefile

pre-install:
	${MKDIR} ${PREFIX}/etc/exim
	${MKDIR} /var/log/exim
	${CHMOD} 750 /var/log/exim
	strip ${WRKSRC}/build*/exim
	strip ${WRKSRC}/build*/exim_dbmbuild
	strip ${WRKSRC}/build*/exim_tidydb
	strip ${WRKSRC}/build*/exim_fixdb
	strip ${WRKSRC}/build*/exim_dumpdb
	strip ${WRKSRC}/build*/exim_lock

post-install:
	(cd ${PREFIX}/sbin; ${RM} -f mailq; ${LN} -s exim mailq)
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${FILESDIR}/exim.sh \
	    > ${PREFIX}/etc/rc.d/exim.sh

.include "../../mk/bsd.pkg.mk"
