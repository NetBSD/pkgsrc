# $NetBSD: Makefile,v 1.27 2001/12/19 17:11:02 ad Exp $

DISTNAME=	exim-3.34
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_PERL5=	yes

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${WRKSRC}/Local/Makefile.netbsd \
	    > ${WRKSRC}/Local/Makefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/exim
	${INSTALL_DATA_DIR} /var/log/exim
	${CHMOD} 750 /var/log/exim
	strip ${WRKSRC}/build*/exim
	strip ${WRKSRC}/build*/exim_dbmbuild
	strip ${WRKSRC}/build*/exim_tidydb
	strip ${WRKSRC}/build*/exim_fixdb
	strip ${WRKSRC}/build*/exim_dumpdb
	strip ${WRKSRC}/build*/exim_lock

post-install:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim \
	    > ${PREFIX}/etc/rc.d/exim
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim_newaliases \
	    > ${PREFIX}/sbin/exim_newaliases
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${PREFIX}/etc/exim/mailer.conf.exim
	${CP} ${FILESDIR}/exim.8 ${PREFIX}/man/man8/exim.8

.include "../../mk/bsd.pkg.mk"
