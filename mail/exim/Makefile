# $NetBSD: Makefile,v 1.17 2001/01/24 21:07:35 ad Exp $

DISTNAME=	exim-3.20
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/
DISTFILES=	exim-3.20.tar.gz exim-html-3.20.tar.gz

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/

USE_PERL5=	yes
MESSAGE_FILE=	${WRKDIR}/MESSAGE

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd
	${SED} "s,@PREFIX@,${PREFIX}," < ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

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
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${FILESDIR}/mailer.conf.exim \
	    > ${PREFIX}/etc/exim/mailer.conf.exim
	${MKDIR} ${PREFIX}/man/man8
	${CP} ${FILESDIR}/exim.8 ${PREFIX}/man/man8/exim.8
	${MKDIR} ${PREFIX}/share/doc/exim
	${RM} ${WRKDIR}/exim-html-3.20/doc/html/spec
	${CP} -R ${WRKDIR}/exim-html-3.20/doc/html/* ${PREFIX}/share/doc/exim

.include "../../mk/bsd.pkg.mk"
