# $NetBSD: Makefile,v 1.9 1999/12/10 00:26:14 ad Exp $

DISTNAME=	exim-3.12
CATEGORIES=	mail net

MASTER_SITES=	ftp://ftp.exim.org/pub/exim/ \
		ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/

DISTFILES=	exim-3.12.tar.gz exim-html-3.10.tar.gz
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
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${FILESDIR}/exim.sh \
	    > ${PREFIX}/etc/rc.d/exim.sh
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${FILESDIR}/exim_newaliases \
	    > ${PREFIX}/sbin/exim_newaliases
	chmod ugo+x ${PREFIX}/sbin/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${FILESDIR}/mailer.conf.exim \
	    > ${PREFIX}/etc/exim/mailer.conf.exim
	${MKDIR} ${PREFIX}/man/man8
	${CP} ${FILESDIR}/exim.8 ${PREFIX}/man/man8/exim.8
	${MKDIR} ${PREFIX}/share/doc/exim
	${CP} -R ${WRKDIR}/exim-html-3.10/doc/html/* ${PREFIX}/share/doc/exim

.include "../../mk/bsd.pkg.mk"
